//
// Created by Valentin on 27.11.2020.
//

#include "polyominos.h"

using namespace std;

Configuration configurationInitiale(ConfigInitiales config) {
	switch (config) {
		case ConfigInitiales::TETRAMINO_T:
			return TETRAMINO_T;
		default:
			return TETRAMINO_T;
	}
}
