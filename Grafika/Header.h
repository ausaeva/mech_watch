#ifndef HEADER_H_
#define HEADER_H_

const int x = 150 - 5;
const int y = 150 - 5;
const int RADIUS = (300 / 2) - 5;

struct Time {
	int hour;
	int minute;
	int second;
};

struct x1y1 {
	int x1;
	int y1;
};

Time get_local_time();//Получаем текущее время в виде структуры


x1y1 find_x1y1_hour(int i);// определяем формулу по которой рассчитываем час
x1y1 find_x1y1_minute(int i);// определяем формулу по которой рассчитываем минуты
x1y1 find_x1y1_cecond(int i);// определяем формулу по которой рассчитываем секунды

void create_line(int x1, int y1);// рисуем линию по полученным координатам












#endif 
