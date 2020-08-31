#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string.h> 

using namespace std;

const int ScreenWidth = 240;
const int ScreenHeigth = 80;

const float aFOV = 3.14f / 3.0f;
float aPOV = 3 * 3.14f / 2;

const float VisibilityRange = 30.0f;

const int MapWidth = 16;
const int MapHeigth = 16;

char floorPixels(float Floor) {

	float start_of_Floor = ScreenHeigth / 2;
	float Quarter = (start_of_Floor + (ScreenHeigth / 2) / 4);
	float twoQuarters = (start_of_Floor + 2 * (ScreenHeigth / 2) / 4);
	float threeQuarters = (start_of_Floor + 3 * (ScreenHeigth / 2) / 4);

	if (Floor < Quarter)
		return '.';
	else if (Floor >= Quarter && Floor < twoQuarters)
		return 'o';
	else if (Floor >= twoQuarters && Floor < start_of_Floor + threeQuarters)
		return 'O';
	else
		return '*';

}

int main() {

	char map[256] = ""; {
		memcpy(map + strlen(map), "################", 16);
		memcpy(map + strlen(map), "#..........#...#", 16);
		memcpy(map + strlen(map), "#..........#...#", 16);
		memcpy(map + strlen(map), "#######....#...#", 16);
		memcpy(map + strlen(map), "#..............#", 16);
		memcpy(map + strlen(map), "#..............#", 16);
		memcpy(map + strlen(map), "#.##..########.#", 16);
		memcpy(map + strlen(map), "#....#..#..#####", 16);
		memcpy(map + strlen(map), "#####....#######", 16);
		memcpy(map + strlen(map), "#..............#", 16);
		memcpy(map + strlen(map), "#..............#", 16);
		memcpy(map + strlen(map), "#..............#", 16);
		memcpy(map + strlen(map), "#..............#", 16);
		memcpy(map + strlen(map), "#..............#", 16);
		memcpy(map + strlen(map), "#..............#", 16);
		memcpy(map + strlen(map), "################", 16);
	}

	char screenBuffer[ScreenWidth * ScreenHeigth + ScreenHeigth + 1] = "";
	float xPlayer = 7;
	float yPlayer = 14;


	for (int j = 0; j < 10000; j++) {
		system("cls");// slow too much

		int x = -1;
		for (float aDirection = aPOV - aFOV / 2; aDirection <= aPOV + aFOV / 2; aDirection += aFOV / ScreenWidth) {
			x++;

			float DistanceToWall = 0.0f;

			float xUnitVector = cos(aDirection);
			float yUnitVector = sin(aDirection);

			bool HitWall = false;


			while (!HitWall && (DistanceToWall <= VisibilityRange)) {

				DistanceToWall += 0.1f;

				float xSum = xPlayer + xUnitVector * DistanceToWall;
				float ySum = yPlayer + yUnitVector * DistanceToWall;

				if (xSum <= 0 || ySum <= 0 || xSum > MapWidth || ySum > MapHeigth)
					HitWall = true;

				else if (map[(int)xSum + (int)ySum * MapWidth] == '#')
					HitWall = true;
			}

			float Ceiling = ScreenHeigth / 2 - (ScreenHeigth / 2) / DistanceToWall;
			float Floor = ScreenHeigth - Ceiling;

			for (int y = 0; y < ScreenHeigth; y++) {
				char pixelColor;

				if (y <= Ceiling)
					pixelColor = '.';
				else if (y > Ceiling && y < Floor) {
					if (DistanceToWall >= VisibilityRange)
						pixelColor = ' ';
					pixelColor = '|';
				}
				else
					pixelColor = '.';// floorPixels(y);

				screenBuffer[y * ScreenWidth + x + y] = pixelColor;

				if (x == 0)
					screenBuffer[y * ScreenWidth + y + ScreenWidth] = '\n';
			}

		}

		fprintf(stdout, "%s", screenBuffer);
		aPOV += 0.1f;
	}



	return 0;
}
