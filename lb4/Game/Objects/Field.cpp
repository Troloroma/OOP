#include "Field.h"

Field::Field() {
	width = 0;
	height = 0;
	board = nullptr;
	enter = nullptr;
	exit = nullptr;
}

int Field::getEnemyInd(Grid* obj) {
	for (int i = 0; i < enemies.size(); i++) {
		if (obj == enemies[i]) {
			return i;
		}
	}
	return -1;
}
Grid* Field::getEnter() { return enter;}
Grid* Field::getExit() { return exit;}
Grid* Field::getPlayer() { return player;}
int Field::getWidth() { return width;}
int Field::getHeight() { return height;}
void Field::setEnter(Grid* obj) { enter = obj;}
void Field::setExit(Grid* obj) { exit = obj;}
void Field::setPlayer(Grid* obj) { player = obj;}
void Field::setWidth(int value) { width = value;}
void Field::setHeight(int value) { height = value;}
int Field::getStartEnemiesAmount() {return startEnemiesAmount;}

void Field::startFinishGeneraton() {
	int enter_coords[2] = { 0, 0 };
	int exit_coords[2] = { 0, 0 };
	enter_coords[0] = std::rand() % this->width;
	enter_coords[1] = std::rand() % this->height;
	int check = 1, x_cord, y_cord;
	while (check == 1) {
		x_cord = std::rand() % width;
		y_cord = std::rand() % height;
		if (x_cord == enter_coords[0] && ((y_cord != enter_coords[1]) && (y_cord != enter_coords[1] - 1) && (y_cord != enter_coords[1] + 1))) {
			check = 0;
		}
		else {
			if (y_cord == enter_coords[1] && ((x_cord != enter_coords[0]) && (x_cord != enter_coords[0] - 1) && (x_cord != enter_coords[0] + 1))) {
				check = 0;
			}
			else {
				if (y_cord != enter_coords[1] && x_cord != enter_coords[0]) {
					check = 0;
				}
			}
		}
	}
	exit_coords[0] = x_cord;
	exit_coords[1] = y_cord;
	this->board[enter_coords[0]][enter_coords[1]].setType("START");
	this->board[exit_coords[0]][exit_coords[1]].setType("FINISH");
	this->enter = &board[enter_coords[0]][enter_coords[1]];
	this->exit = &board[exit_coords[0]][exit_coords[1]];
}
void Field::playerSpawn() {
	Player* player = new Player;
	this->board[enter->getX()][enter->getY()].setEntity(player);
	this->player = &board[enter->getX()][enter->getY()];
}
void Field::bordersSpawn() {
	int status;
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			status = std::rand() % 2;
			if (status == 1) {
				this->board[i][j] = Grid(i, j, "EMPTY");
			}
			else {
				this->board[i][j] = Grid(i, j, "EMPTY");
			}
		}
	}
}
void Field::enemiesGeneration() {
	int totalCells = this->height * this->width;
	for (int i = 0; i < ((totalCells / 20) + 1); i++) {
		bool check = 1;
		int x_cord, y_cord;
		while (check == 1) {
			x_cord = std::rand() % width;
			y_cord = std::rand() % height;
			if (this->board[x_cord][y_cord].getType() == "EMPTY" && this->board[x_cord][y_cord].getEntity() == nullptr) {
				if ((i % 3) == 0) {
					Knight* enemy = new Knight;
					this->board[x_cord][y_cord].setEntity(enemy);
				}
				if ((i % 3) == 1) {
					Horseman* enemy = new Horseman;
					this->board[x_cord][y_cord].setEntity(enemy);
				}
				if ((i % 3) == 2) {
					Wolf* enemy = new Wolf;
					this->board[x_cord][y_cord].setEntity(enemy);
				}
				this->enemies.push_back(&this->board[x_cord][y_cord]);
				check = 0;
			}
		}
	}
	startEnemiesAmount = enemies.size();
}
void Field::itemsGeneration() {
	int totalCells = this->height * this->width;
	for (int i = 0; i < ((totalCells / 15) + 1); i++) {
		bool check = 1;
		int x_cord, y_cord;
		while (check == 1) {
			x_cord = std::rand() % width;
			y_cord = std::rand() % height;
			if (this->board[x_cord][y_cord].getType() == "EMPTY" && this->board[x_cord][y_cord].getEntity() == nullptr) {
				if ((i % 3) == 0) {
					Medkit* item = new Medkit;
					this->board[x_cord][y_cord].setEntity(item);
				}
				if ((i % 3) == 1) {
					Shield* item = new Shield;
					this->board[x_cord][y_cord].setEntity(item);
				}
				if ((i % 3) == 2) {
					Power* item = new Power;
					this->board[x_cord][y_cord].setEntity(item);
				}
				check = 0;
			}
		}
	}
}
void Field::moveEntity(Grid cell, char direction, int enemyNum) {
	int x = -2;
	int y = -2;
	if (direction == 'W' && cell.getX() != 0) {
		x = cell.getX() - 1;
		y = cell.getY();
	}
	if (direction == 'S' && cell.getX() != width - 1) {
		x = cell.getX() + 1;
		y = cell.getY();

	}
	if (direction == 'A' && cell.getY() != 0) {
		x = cell.getX();
		y = cell.getY() - 1;
	}
	if (direction == 'D' && cell.getY() != height - 1) {
		x = cell.getX();
		y = cell.getY() + 1;
	}
	if (x != -2 && y != -2) {
		if (cell.getEntity() != nullptr) {
			if ((typeid((*cell.getEntity())).name() == typeid(Player).name())) {
				if (board[x][y].getEntity() != nullptr) {
					if (typeid(*board[x][y].getEntity()).name() != typeid(Knight).name() && typeid(*board[x][y].getEntity()).name() != typeid(Horseman).name() && typeid(*board[x][y].getEntity()).name() != typeid(Wolf).name()) { // ����������� �������� �� enemy
						if (typeid(*board[x][y].getEntity()).name() == typeid(Medkit).name() || typeid(*board[x][y].getEntity()).name() == typeid(Shield).name() || typeid(*board[x][y].getEntity()).name() == typeid(Power).name()) {
							(dynamic_cast<Player&>(*player->getEntity())).takeItem(board[x][y].getEntity());
							delete board[x][y].getEntity();
						}
						board[x][y].setEntity(cell.getEntity());
						board[cell.getX()][cell.getY()].setEntity(nullptr);
						player = &board[x][y];
					}
					else {
						(dynamic_cast<Player&>(*player->getEntity())).attack(board[x][y].getEntity());
						(dynamic_cast<Enemy&>(*board[x][y].getEntity())).attack(player->getEntity());
						if ((dynamic_cast<Enemy&>(*board[x][y].getEntity())).getHp() <= 0) {
							int iter = getEnemyInd(&board[x][y]);
							enemies.erase(enemies.cbegin() + iter);
							delete (board[x][y].getEntity());
							board[x][y].setEntity(cell.getEntity());
							board[cell.getX()][cell.getY()].setEntity(nullptr);
							player = &board[x][y];
						}
					}
				}
				else {
					board[x][y].setEntity(cell.getEntity());
					board[cell.getX()][cell.getY()].setEntity(nullptr);
					player = &board[x][y];
				}
			}
			else {
				if (board[x][y].getEntity() != nullptr) {
					if (typeid(*board[x][y].getEntity()).name() != typeid(Player).name() && typeid(*board[x][y].getEntity()).name() != typeid(Knight).name() && typeid(*board[x][y].getEntity()).name() != typeid(Horseman).name() && typeid(*board[x][y].getEntity()).name() != typeid(Wolf).name()) {
						if (typeid(*board[x][y].getEntity()).name() == typeid(Medkit).name() || typeid(*board[x][y].getEntity()).name() == typeid(Power).name() || typeid(*board[x][y].getEntity()).name() == typeid(Shield).name()) {
							delete board[x][y].getEntity();
						}
						board[x][y].setEntity(cell.getEntity());
						board[cell.getX()][cell.getY()].setEntity(nullptr);
						enemies[enemyNum] = &board[x][y];
					}
				}
				else {
					board[x][y].setEntity(cell.getEntity());
					board[cell.getX()][cell.getY()].setEntity(nullptr);
					enemies[enemyNum] = &board[x][y];
				}
			}
		}
	}
}
Field::Field(int userWidth, int userHeight) {
	this->width = std::min(30, std::max(2, userWidth));
	this->height = std::min(30, std::max(2, userHeight));
	board = new Grid * [width];
	for (int i = 0; i < width; i++) {
		board[i] = new Grid[height];
	}
	bordersSpawn();
	startFinishGeneraton();
	playerSpawn();
	enemiesGeneration();
	itemsGeneration();
}

Field::Field(const Field& obj) {
	this->width = obj.width;
	this->height = obj.height;
	this->enter = obj.enter;
	this->exit = obj.exit;
	this->player = obj.player;
	for (int i = 0; i < obj.enemies.size(); i++) {
		this->enemies.push_back(obj.enemies[i]);
	}
	board = new Grid * [width];
	for (int i = 0; i < width; i++) {
		board[i] = new Grid[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			board[i][j] = Grid(i, j, obj.board[i][j].getType());
			board[i][j].setEntity(obj.board[i][j].getEntity());
		}
	}
}

Field& Field::operator=(const Field& obj) {
	if (this != &obj) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				if (board[i][j].getEntity() != nullptr) {
					delete (board[i][j].getEntity());
				}
			}
		}
		for (int i = 0; i < width; i++) {
			delete[] board[i];
		}
		delete[] board;
		this->width = obj.width;
		this->height = obj.height;
		this->enter = obj.enter;
		this->exit = obj.exit;
		this->player = obj.player;
		for (int i = 0; i < obj.enemies.size(); i++) {
			this->enemies.push_back(obj.enemies[i]);
		}
		board = new Grid * [width];
		for (int i = 0; i < width; i++) {
			board[i] = new Grid[height];
		}
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				board[i][j] = Grid(i, j, obj.board[i][j].getType());
				board[i][j].setEntity(obj.board[i][j].getEntity());
			}
		}
	}
	return *this;
}


Field::Field(Field&& obj) {
	std::swap(board, obj.board);
	std::swap(width, obj.width);
	std::swap(height, obj.height);
	std::swap(enter, obj.enter);
	std::swap(exit, obj.exit);
	std::swap(player, obj.player);
	std::swap(enemies, obj.enemies);
}


Field& Field::operator=(Field&& obj) {
	if (this != &obj) {
		std::swap(board, obj.board);
		std::swap(width, obj.width);
		std::swap(height, obj.height);
		std::swap(enter, obj.enter);
		std::swap(exit, obj.exit);
		std::swap(player, obj.player);
		std::swap(enemies, obj.enemies);
	}
	return *this;
}


Field::~Field() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (board[i][j].getEntity() != nullptr) {
				delete (board[i][j].getEntity());
			}
		}
	}
	for (int i = 0; i < width; i++) {
		delete[] board[i];
	}
	delete[] board;
}
