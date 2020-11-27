//
// Created by Valentin on 27.11.2020.
//

#ifndef LABO4_POLYOMINOS_H
#define LABO4_POLYOMINOS_H

#include <vector>

using Configuration = std::vector<std::vector<size_t>>;

enum class ConfigInitiales {
	TETRAMINO_T
};

const Configuration TETRAMINO_T = {
	{4, 4},
	{4, 5},
	{4, 6},
	{5, 5}
};

Configuration configurationInitiale(ConfigInitiales config);

#endif //LABO4_POLYOMINOS_H
