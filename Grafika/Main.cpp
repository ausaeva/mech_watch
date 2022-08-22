#include "headers/graphics.h"
#include <iostream>
#include "header.h"
#include <ctime>
using namespace std;

const int WIDTH = 300;                      
const int HEIGHT = 300;

bool first_start = true;



int main() {

	initwindow(WIDTH, HEIGHT, "Анимация", 0, 0, true); 
	Time local_time;
	local_time = get_local_time();
	x1y1 coord_hour;	
	x1y1 coord_minute;
	x1y1 coord_second;	

	//По локальнуму времени нужно как то определить координаты второй точки линии. по полученным координатам нарисовать час, минуту и секунду
	coord_hour = find_x1y1_hour(local_time.hour);         			

	create_line(coord_hour.x1, coord_hour.y1);

	coord_minute = find_x1y1_minute(local_time.minute);			

	create_line(coord_minute.x1, coord_minute.y1);

	coord_second = find_x1y1_cecond(local_time.second);

	create_line(coord_second.x1, coord_second.y1);



	while (true) {
		setcolor(GREEN);
	    circle(x,y,RADIUS);

		if (first_start) {//как определить что это не первая итерация

			coord_hour = find_x1y1_hour(local_time.hour);

			create_line(coord_hour.x1, coord_hour.y1);

			coord_minute = find_x1y1_minute(local_time.minute);

			create_line(coord_minute.x1, coord_minute.y1);

			coord_second = find_x1y1_cecond(local_time.second);

			create_line(coord_second.x1, coord_second.y1);

			if (local_time.minute == 60) {
				local_time.hour += 1;
				local_time.minute = 0;
			}


			if (local_time.second == 60) {
				local_time.minute += 1;
				local_time.second += 0;
			}

			local_time.second += 1;

			first_start = false;

		}

		else {

			coord_second = find_x1y1_cecond(local_time.second);

			create_line(coord_second.x1, coord_second.y1);     //Рисуем секундную стрелку

			if (local_time.minute == 60) {
				
				coord_hour = find_x1y1_hour(local_time.hour);     //Если минут 60 рисуем часовую
				create_line(coord_hour.x1, coord_hour.y1);

				local_time.hour += 1;

				local_time.minute = 0;   //обнуляем минуту
			}

			//не пойму в каком месте обнулять час

			if (local_time.hour == 12) {
				local_time.hour = 0; // обнуляем час
			}

			else if (local_time.minute != 60 && local_time.minute%15 == 0) {  //Если минут  15, 30  или 45 двигаем часовую.

				coord_hour = find_x1y1_hour(local_time.hour);
				create_line(coord_hour.x1, coord_hour.y1);

				local_time.hour += 1;

				local_time.minute = 0;
			}

			if (local_time.second == 60) {   // на 60 секунде рисуем минутную

				coord_minute = find_x1y1_minute(local_time.minute);
				create_line(coord_minute.x1, coord_minute.y1);

				local_time.minute += 1; //увеличиваем минуту
				local_time.second = 0;  // обнуляем секунду
			}
			else {
				local_time.second += 1; //увеличиваем секунду
			}

			
			


			
		}

		
		

		swapbuffers(); // делаем активную страницу видимой
		delay(1); 
		if (kbhit()) break; // если нажата клавиша - завершить работу
	}
	closegraph();
}