#include "headers/graphics.h"
#include <iostream>
#include "header.h"
#include <ctime>
using namespace std;

const int WIDTH = 300;                      
const int HEIGHT = 300;

bool first_start = true;



int main() {

	initwindow(WIDTH, HEIGHT, "��������", 0, 0, true); 
	Time local_time;
	local_time = get_local_time();
	x1y1 coord_hour;	
	x1y1 coord_minute;
	x1y1 coord_second;	

	//�� ���������� ������� ����� ��� �� ���������� ���������� ������ ����� �����. �� ���������� ����������� ���������� ���, ������ � �������
	coord_hour = find_x1y1_hour(local_time.hour);         			

	create_line(coord_hour.x1, coord_hour.y1);

	coord_minute = find_x1y1_minute(local_time.minute);			

	create_line(coord_minute.x1, coord_minute.y1);

	coord_second = find_x1y1_cecond(local_time.second);

	create_line(coord_second.x1, coord_second.y1);



	while (true) {
		setcolor(GREEN);
	    circle(x,y,RADIUS);

		if (first_start) {//��� ���������� ��� ��� �� ������ ��������

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

			create_line(coord_second.x1, coord_second.y1);     //������ ��������� �������

			if (local_time.minute == 60) {
				
				coord_hour = find_x1y1_hour(local_time.hour);     //���� ����� 60 ������ �������
				create_line(coord_hour.x1, coord_hour.y1);

				local_time.hour += 1;

				local_time.minute = 0;   //�������� ������
			}

			//�� ����� � ����� ����� �������� ���

			if (local_time.hour == 12) {
				local_time.hour = 0; // �������� ���
			}

			else if (local_time.minute != 60 && local_time.minute%15 == 0) {  //���� �����  15, 30  ��� 45 ������� �������.

				coord_hour = find_x1y1_hour(local_time.hour);
				create_line(coord_hour.x1, coord_hour.y1);

				local_time.hour += 1;

				local_time.minute = 0;
			}

			if (local_time.second == 60) {   // �� 60 ������� ������ ��������

				coord_minute = find_x1y1_minute(local_time.minute);
				create_line(coord_minute.x1, coord_minute.y1);

				local_time.minute += 1; //����������� ������
				local_time.second = 0;  // �������� �������
			}
			else {
				local_time.second += 1; //����������� �������
			}

			
			


			
		}

		
		

		swapbuffers(); // ������ �������� �������� �������
		delay(1); 
		if (kbhit()) break; // ���� ������ ������� - ��������� ������
	}
	closegraph();
}