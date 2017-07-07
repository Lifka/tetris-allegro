//
// Created by lifka on 18/06/17.
//

#include <cstdlib>
#include <iostream>
#include <random>
#include "Factory.h"
#include "ColorPalette.h"

Piece Factory::createPiece(PieceType type) {
    std::vector<std::vector<int> > rotation0;
    std::vector<std::vector<int> > rotation90;
    std::vector<std::vector<int> > rotation180;
    std::vector<std::vector<int> > rotation270;

    Rotation current_rotation = degrees0;


    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> rnd(0,3); // distribution in range [0, 3]
    unsigned long random = rnd(rng);

    switch (random) {
        case 0:
            current_rotation = degrees0;
            break;
        case 1:
            current_rotation = degrees90;
            break;
        case 2:
            current_rotation = degrees180;
            break;
        case 3:
            current_rotation = degrees270;
            break;
    }

    switch (type) {
        case square: {
            int line0_0_square[] = {0, 0, 0, 0, 0};
            int line0_1_square[] = {0, 0, 0, 0, 0};
            int line0_2_square[] = {0, 0, 2, 1, 0};
            int line0_3_square[] = {0, 0, 1, 1, 0};
            int line0_4_square[] = {0, 0, 0, 0, 0};
            rotation0.push_back(std::vector<int>(line0_0_square,
                                                 line0_0_square + sizeof line0_0_square / sizeof line0_0_square[0]));
            rotation0.push_back(std::vector<int>(line0_1_square,
                                                      line0_1_square + sizeof line0_1_square / sizeof line0_1_square[0]));
            rotation0.push_back(std::vector<int>(line0_2_square,
                                                 line0_2_square + sizeof line0_2_square / sizeof line0_2_square[0]));
            rotation0.push_back(std::vector<int>(line0_3_square,
                                                 line0_3_square + sizeof line0_3_square / sizeof line0_3_square[0]));
            rotation0.push_back(std::vector<int>(line0_4_square,
                                                 line0_4_square + sizeof line0_4_square / sizeof line0_4_square[0]));

            int line90_0_square[] = {0, 0, 0, 0, 0};
            int line90_1_square[] = {0, 0, 0, 0, 0};
            int line90_2_square[] = {0, 0, 2, 1, 0};
            int line90_3_square[] = {0, 0, 1, 1, 0};
            int line90_4_square[] = {0, 0, 0, 0, 0};
                rotation90.push_back(std::vector<int>(line90_0_square, line90_0_square +
                                                                       sizeof line90_0_square / sizeof line90_0_square[0]));
                rotation90.push_back(std::vector<int>(line90_1_square, line90_1_square +
                                                                       sizeof line90_1_square / sizeof line90_1_square[0]));
            rotation90.push_back(std::vector<int>(line90_2_square, line90_2_square +
                                                                   sizeof line90_2_square / sizeof line90_2_square[0]));
            rotation90.push_back(std::vector<int>(line90_3_square, line90_3_square +
                                                                   sizeof line90_3_square / sizeof line90_3_square[0]));
            rotation90.push_back(std::vector<int>(line90_4_square, line90_4_square +
                                                                   sizeof line90_4_square / sizeof line90_4_square[0]));

            int line180_0_square[] = {0, 0, 0, 0, 0};
            int line180_1_square[] = {0, 0, 0, 0, 0};
            int line180_2_square[] = {0, 0, 2, 1, 0};
            int line180_3_square[] = {0, 0, 1, 1, 0};
            int line180_4_square[] = {0, 0, 0, 0, 0};
            rotation180.push_back(std::vector<int>(line180_0_square, line180_0_square + sizeof line180_0_square /
                                                                                        sizeof line180_0_square[0]));
            rotation180.push_back(std::vector<int>(line180_1_square, line180_1_square + sizeof line180_1_square /
                                                                                        sizeof line180_1_square[0]));
            rotation180.push_back(std::vector<int>(line180_2_square, line180_2_square + sizeof line180_2_square /
                                                                                        sizeof line180_2_square[0]));
            rotation180.push_back(std::vector<int>(line180_3_square, line180_3_square + sizeof line180_3_square /
                                                                                        sizeof line180_3_square[0]));
            rotation180.push_back(std::vector<int>(line180_4_square, line180_4_square + sizeof line180_4_square /
                                                                                        sizeof line180_4_square[0]));

            int line270_0_square[] = {0, 0, 0, 0, 0};
            int line270_1_square[] = {0, 0, 0, 0, 0};
            int line270_2_square[] = {0, 0, 2, 1, 0};
            int line270_3_square[] = {0, 0, 1, 1, 0};
            int line270_4_square[] = {0, 0, 0, 0, 0};
            rotation270.push_back(std::vector<int>(line270_0_square, line270_0_square + sizeof line270_0_square /
                                                                                        sizeof line270_0_square[0]));
            rotation270.push_back(std::vector<int>(line270_1_square, line270_1_square + sizeof line270_1_square /
                                                                                        sizeof line270_1_square[0]));
            rotation270.push_back(std::vector<int>(line270_2_square, line270_2_square + sizeof line270_2_square /
                                                                                        sizeof line270_2_square[0]));
            rotation270.push_back(std::vector<int>(line270_3_square, line270_3_square + sizeof line270_3_square /
                                                                                        sizeof line270_3_square[0]));
            rotation270.push_back(std::vector<int>(line270_4_square, line270_4_square + sizeof line270_4_square /
                                                                                        sizeof line270_4_square[0]));
        }
            break;
        case I: {
            int line0_0_I[] = {0, 0, 0, 0, 0};
            int line0_1_I[] = {0, 0, 0, 0, 0};
            int line0_2_I[] = {0, 1, 2, 1, 1};
            int line0_3_I[] = {0, 0, 0, 0, 0};
            int line0_4_I[] = {0, 0, 0, 0, 0};
            rotation0.push_back(std::vector<int>(line0_0_I, line0_0_I + sizeof line0_0_I / sizeof line0_0_I[0]));
            rotation0.push_back(std::vector<int>(line0_1_I, line0_1_I + sizeof line0_1_I / sizeof line0_1_I[0]));
            rotation0.push_back(std::vector<int>(line0_2_I, line0_2_I + sizeof line0_2_I / sizeof line0_2_I[0]));
            rotation0.push_back(std::vector<int>(line0_3_I, line0_3_I + sizeof line0_3_I / sizeof line0_3_I[0]));
            rotation0.push_back(std::vector<int>(line0_4_I, line0_4_I + sizeof line0_4_I / sizeof line0_4_I[0]));

            int line90_0_I[] = {0, 0, 0, 0, 0};
            int line90_1_I[] = {0, 0, 1, 0, 0};
            int line90_2_I[] = {0, 0, 2, 0, 0};
            int line90_3_I[] = {0, 0, 1, 0, 0};
            int line90_4_I[] = {0, 0, 1, 0, 0};
            rotation90.push_back(std::vector<int>(line90_0_I, line90_0_I + sizeof line90_0_I / sizeof line90_0_I[0]));
            rotation90.push_back(std::vector<int>(line90_1_I, line90_1_I + sizeof line90_1_I / sizeof line90_1_I[0]));
            rotation90.push_back(std::vector<int>(line90_2_I, line90_2_I + sizeof line90_2_I / sizeof line90_2_I[0]));
            rotation90.push_back(std::vector<int>(line90_3_I, line90_3_I + sizeof line90_3_I / sizeof line90_3_I[0]));
            rotation90.push_back(std::vector<int>(line90_4_I, line90_4_I + sizeof line90_4_I / sizeof line90_4_I[0]));

            int line180_0_I[] = {0, 0, 0, 0, 0};
            int line180_1_I[] = {0, 0, 0, 0, 0};
            int line180_2_I[] = {1, 1, 2, 1, 0};
            int line180_3_I[] = {0, 0, 0, 0, 0};
            int line180_4_I[] = {0, 0, 0, 0, 0};
            rotation180.push_back(
                    std::vector<int>(line180_0_I, line180_0_I + sizeof line180_0_I / sizeof line180_0_I[0]));
            rotation180.push_back(
                    std::vector<int>(line180_1_I, line180_1_I + sizeof line180_1_I / sizeof line180_1_I[0]));
            rotation180.push_back(
                    std::vector<int>(line180_2_I, line180_2_I + sizeof line180_2_I / sizeof line180_2_I[0]));
            rotation180.push_back(
                    std::vector<int>(line180_3_I, line180_3_I + sizeof line180_3_I / sizeof line180_3_I[0]));
            rotation180.push_back(
                    std::vector<int>(line180_4_I, line180_4_I + sizeof line180_4_I / sizeof line180_4_I[0]));

            int line270_0_I[] = {0, 0, 1, 0, 0};
            int line270_1_I[] = {0, 0, 1, 0, 0};
            int line270_2_I[] = {0, 0, 2, 0, 0};
            int line270_3_I[] = {0, 0, 1, 0, 0};
            int line270_4_I[] = {0, 0, 0, 0, 0};
            rotation270.push_back(
                    std::vector<int>(line270_0_I, line270_0_I + sizeof line270_0_I / sizeof line270_0_I[0]));
            rotation270.push_back(
                    std::vector<int>(line270_1_I, line270_1_I + sizeof line270_1_I / sizeof line270_1_I[0]));
            rotation270.push_back(
                    std::vector<int>(line270_2_I, line270_2_I + sizeof line270_2_I / sizeof line270_2_I[0]));
            rotation270.push_back(
                    std::vector<int>(line270_3_I, line270_3_I + sizeof line270_3_I / sizeof line270_3_I[0]));
            rotation270.push_back(
                    std::vector<int>(line270_4_I, line270_4_I + sizeof line270_4_I / sizeof line270_4_I[0]));
        }
            break;
        case L: {
            int line0_0_L[] = {0, 0, 0, 0, 0};
            int line0_1_L[] = {0, 0, 1, 0, 0};
            int line0_2_L[] = {0, 0, 2, 0, 0};
            int line0_3_L[] = {0, 0, 1, 1, 0};
            int line0_4_L[] = {0, 0, 0, 0, 0};
            rotation0.push_back(std::vector<int>(line0_0_L, line0_0_L + sizeof line0_0_L / sizeof line0_0_L[0]));
            rotation0.push_back(std::vector<int>(line0_1_L, line0_1_L + sizeof line0_1_L / sizeof line0_1_L[0]));
            rotation0.push_back(std::vector<int>(line0_2_L, line0_2_L + sizeof line0_2_L / sizeof line0_2_L[0]));
            rotation0.push_back(std::vector<int>(line0_3_L, line0_3_L + sizeof line0_3_L / sizeof line0_3_L[0]));
            rotation0.push_back(std::vector<int>(line0_4_L, line0_4_L + sizeof line0_4_L / sizeof line0_4_L[0]));

            int line90_0_L[] = {0, 0, 0, 0, 0};
            int line90_1_L[] = {0, 0, 0, 0, 0};
            int line90_2_L[] = {0, 1, 2, 1, 0};
            int line90_3_L[] = {0, 1, 0, 0, 0};
            int line90_4_L[] = {0, 0, 0, 0, 0};
            rotation90.push_back(std::vector<int>(line90_0_L, line90_0_L + sizeof line90_0_L / sizeof line90_0_L[0]));
            rotation90.push_back(std::vector<int>(line90_1_L, line90_1_L + sizeof line90_1_L / sizeof line90_1_L[0]));
            rotation90.push_back(std::vector<int>(line90_2_L, line90_2_L + sizeof line90_2_L / sizeof line90_2_L[0]));
            rotation90.push_back(std::vector<int>(line90_3_L, line90_3_L + sizeof line90_3_L / sizeof line90_3_L[0]));
            rotation90.push_back(std::vector<int>(line90_4_L, line90_4_L + sizeof line90_4_L / sizeof line90_4_L[0]));

            int line180_0_L[] = {0, 0, 0, 0, 0};
            int line180_1_L[] = {0, 1, 1, 0, 0};
            int line180_2_L[] = {0, 0, 2, 0, 0};
            int line180_3_L[] = {0, 0, 1, 0, 0};
            int line180_4_L[] = {0, 0, 0, 0, 0};
            rotation180.push_back(
                    std::vector<int>(line180_0_L, line180_0_L + sizeof line180_0_L / sizeof line180_0_L[0]));
            rotation180.push_back(
                    std::vector<int>(line180_1_L, line180_1_L + sizeof line180_1_L / sizeof line180_1_L[0]));
            rotation180.push_back(
                    std::vector<int>(line180_2_L, line180_2_L + sizeof line180_2_L / sizeof line180_2_L[0]));
            rotation180.push_back(
                    std::vector<int>(line180_3_L, line180_3_L + sizeof line180_3_L / sizeof line180_3_L[0]));
            rotation180.push_back(
                    std::vector<int>(line180_4_L, line180_4_L + sizeof line180_4_L / sizeof line180_4_L[0]));

            int line270_0_L[] = {0, 0, 0, 0, 0};
            int line270_1_L[] = {0, 0, 0, 1, 0};
            int line270_2_L[] = {0, 1, 2, 1, 0};
            int line270_3_L[] = {0, 0, 0, 0, 0};
            int line270_4_L[] = {0, 0, 0, 0, 0};
            rotation270.push_back(
                    std::vector<int>(line270_0_L, line270_0_L + sizeof line270_0_L / sizeof line270_0_L[0]));
            rotation270.push_back(
                    std::vector<int>(line270_1_L, line270_1_L + sizeof line270_1_L / sizeof line270_1_L[0]));
            rotation270.push_back(
                    std::vector<int>(line270_2_L, line270_2_L + sizeof line270_2_L / sizeof line270_2_L[0]));
            rotation270.push_back(
                    std::vector<int>(line270_3_L, line270_3_L + sizeof line270_3_L / sizeof line270_3_L[0]));
            rotation270.push_back(
                    std::vector<int>(line270_4_L, line270_4_L + sizeof line270_4_L / sizeof line270_4_L[0]));
        }
            break;
        case L_mirrored: {
            int line0_0_L_mirrored[] = {0, 0, 0, 0, 0};
            int line0_1_L_mirrored[] = {0, 0, 1, 0, 0};
            int line0_2_L_mirrored[] = {0, 0, 2, 0, 0};
            int line0_3_L_mirrored[] = {0, 1, 1, 0, 0};
            int line0_4_L_mirrored[] = {0, 0, 0, 0, 0};
            rotation0.push_back(std::vector<int>(line0_0_L_mirrored, line0_0_L_mirrored + sizeof line0_0_L_mirrored /
                                                                                          sizeof line0_0_L_mirrored[0]));
            rotation0.push_back(std::vector<int>(line0_1_L_mirrored, line0_1_L_mirrored + sizeof line0_1_L_mirrored /
                                                                                          sizeof line0_1_L_mirrored[0]));
            rotation0.push_back(std::vector<int>(line0_2_L_mirrored, line0_2_L_mirrored + sizeof line0_2_L_mirrored /
                                                                                          sizeof line0_2_L_mirrored[0]));
            rotation0.push_back(std::vector<int>(line0_3_L_mirrored, line0_3_L_mirrored + sizeof line0_3_L_mirrored /
                                                                                          sizeof line0_3_L_mirrored[0]));
            rotation0.push_back(std::vector<int>(line0_4_L_mirrored, line0_4_L_mirrored + sizeof line0_4_L_mirrored /
                                                                                          sizeof line0_4_L_mirrored[0]));

            int line90_0_L_mirrored[] = {0, 0, 0, 0, 0};
            int line90_1_L_mirrored[] = {0, 1, 0, 0, 0};
            int line90_2_L_mirrored[] = {0, 1, 2, 1, 0};
            int line90_3_L_mirrored[] = {0, 0, 0, 0, 0};
            int line90_4_L_mirrored[] = {0, 0, 0, 0, 0};
            rotation90.push_back(std::vector<int>(line90_0_L_mirrored, line90_0_L_mirrored +
                                                                       sizeof line90_0_L_mirrored /
                                                                       sizeof line90_0_L_mirrored[0]));
            rotation90.push_back(std::vector<int>(line90_1_L_mirrored, line90_1_L_mirrored +
                                                                       sizeof line90_1_L_mirrored /
                                                                       sizeof line90_1_L_mirrored[0]));
            rotation90.push_back(std::vector<int>(line90_2_L_mirrored, line90_2_L_mirrored +
                                                                       sizeof line90_2_L_mirrored /
                                                                       sizeof line90_2_L_mirrored[0]));
            rotation90.push_back(std::vector<int>(line90_3_L_mirrored, line90_3_L_mirrored +
                                                                       sizeof line90_3_L_mirrored /
                                                                       sizeof line90_3_L_mirrored[0]));
            rotation90.push_back(std::vector<int>(line90_4_L_mirrored, line90_4_L_mirrored +
                                                                       sizeof line90_4_L_mirrored /
                                                                       sizeof line90_4_L_mirrored[0]));

            int line180_0_L_mirrored[] = {0, 0, 0, 0, 0};
            int line180_1_L_mirrored[] = {0, 0, 1, 1, 0};
            int line180_2_L_mirrored[] = {0, 0, 2, 0, 0};
            int line180_3_L_mirrored[] = {0, 0, 1, 0, 0};
            int line180_4_L_mirrored[] = {0, 0, 0, 0, 0};
            rotation180.push_back(std::vector<int>(line180_0_L_mirrored, line180_0_L_mirrored +
                                                                         sizeof line180_0_L_mirrored /
                                                                         sizeof line180_0_L_mirrored[0]));
            rotation180.push_back(std::vector<int>(line180_1_L_mirrored, line180_1_L_mirrored +
                                                                         sizeof line180_1_L_mirrored /
                                                                         sizeof line180_1_L_mirrored[0]));
            rotation180.push_back(std::vector<int>(line180_2_L_mirrored, line180_2_L_mirrored +
                                                                         sizeof line180_2_L_mirrored /
                                                                         sizeof line180_2_L_mirrored[0]));
            rotation180.push_back(std::vector<int>(line180_3_L_mirrored, line180_3_L_mirrored +
                                                                         sizeof line180_3_L_mirrored /
                                                                         sizeof line180_3_L_mirrored[0]));
            rotation180.push_back(std::vector<int>(line180_4_L_mirrored, line180_4_L_mirrored +
                                                                         sizeof line180_4_L_mirrored /
                                                                         sizeof line180_4_L_mirrored[0]));

            int line270_0_L_mirrored[] = {0, 0, 0, 0, 0};
            int line270_1_L_mirrored[] = {0, 0, 0, 0, 0};
            int line270_2_L_mirrored[] = {0, 1, 2, 1, 0};
            int line270_3_L_mirrored[] = {0, 0, 0, 1, 0};
            int line270_4_L_mirrored[] = {0, 0, 0, 0, 0};
            rotation270.push_back(std::vector<int>(line270_0_L_mirrored, line270_0_L_mirrored +
                                                                         sizeof line270_0_L_mirrored /
                                                                         sizeof line270_0_L_mirrored[0]));
            rotation270.push_back(std::vector<int>(line270_1_L_mirrored, line270_1_L_mirrored +
                                                                         sizeof line270_1_L_mirrored /
                                                                         sizeof line270_1_L_mirrored[0]));
            rotation270.push_back(std::vector<int>(line270_2_L_mirrored, line270_2_L_mirrored +
                                                                         sizeof line270_2_L_mirrored /
                                                                         sizeof line270_2_L_mirrored[0]));
            rotation270.push_back(std::vector<int>(line270_3_L_mirrored, line270_3_L_mirrored +
                                                                         sizeof line270_3_L_mirrored /
                                                                         sizeof line270_3_L_mirrored[0]));
            rotation270.push_back(std::vector<int>(line270_4_L_mirrored, line270_4_L_mirrored +
                                                                         sizeof line270_4_L_mirrored /
                                                                         sizeof line270_4_L_mirrored[0]));
        }
            break;
        case N: {
            int line0_0_N[] = {0, 0, 0, 0, 0};
            int line0_1_N[] = {0, 0, 0, 1, 0};
            int line0_2_N[] = {0, 0, 2, 1, 0};
            int line0_3_N[] = {0, 0, 1, 0, 0};
            int line0_4_N[] = {0, 0, 0, 0, 0};
            rotation0.push_back(std::vector<int>(line0_0_N, line0_0_N + sizeof line0_0_N / sizeof line0_0_N[0]));
            rotation0.push_back(std::vector<int>(line0_1_N, line0_1_N + sizeof line0_1_N / sizeof line0_1_N[0]));
            rotation0.push_back(std::vector<int>(line0_2_N, line0_2_N + sizeof line0_2_N / sizeof line0_2_N[0]));
            rotation0.push_back(std::vector<int>(line0_3_N, line0_3_N + sizeof line0_3_N / sizeof line0_3_N[0]));
            rotation0.push_back(std::vector<int>(line0_4_N, line0_4_N + sizeof line0_4_N / sizeof line0_4_N[0]));

            int line90_0_N[] = {0, 0, 0, 0, 0};
            int line90_1_N[] = {0, 0, 0, 0, 0};
            int line90_2_N[] = {0, 1, 2, 0, 0};
            int line90_3_N[] = {0, 0, 1, 1, 0};
            int line90_4_N[] = {0, 0, 0, 0, 0};
            rotation90.push_back(std::vector<int>(line90_0_N, line90_0_N + sizeof line90_0_N / sizeof line90_0_N[0]));
            rotation90.push_back(std::vector<int>(line90_1_N, line90_1_N + sizeof line90_1_N / sizeof line90_1_N[0]));
            rotation90.push_back(std::vector<int>(line90_2_N, line90_2_N + sizeof line90_2_N / sizeof line90_2_N[0]));
            rotation90.push_back(std::vector<int>(line90_3_N, line90_3_N + sizeof line90_3_N / sizeof line90_3_N[0]));
            rotation90.push_back(std::vector<int>(line90_4_N, line90_4_N + sizeof line90_4_N / sizeof line90_4_N[0]));

            int line180_0_N[] = {0, 0, 0, 0, 0};
            int line180_1_N[] = {0, 0, 1, 0, 0};
            int line180_2_N[] = {0, 1, 2, 0, 0};
            int line180_3_N[] = {0, 1, 0, 0, 0};
            int line180_4_N[] = {0, 0, 0, 0, 0};
            rotation180.push_back(
                    std::vector<int>(line180_0_N, line180_0_N + sizeof line180_0_N / sizeof line180_0_N[0]));
            rotation180.push_back(
                    std::vector<int>(line180_1_N, line180_1_N + sizeof line180_1_N / sizeof line180_1_N[0]));
            rotation180.push_back(
                    std::vector<int>(line180_2_N, line180_2_N + sizeof line180_2_N / sizeof line180_2_N[0]));
            rotation180.push_back(
                    std::vector<int>(line180_3_N, line180_3_N + sizeof line180_3_N / sizeof line180_3_N[0]));
            rotation180.push_back(
                    std::vector<int>(line180_4_N, line180_4_N + sizeof line180_4_N / sizeof line180_4_N[0]));

            int line270_0_N[] = {0, 0, 0, 0, 0};
            int line270_1_N[] = {0, 1, 1, 0, 0};
            int line270_2_N[] = {0, 0, 2, 1, 0};
            int line270_3_N[] = {0, 0, 0, 0, 0};
            int line270_4_N[] = {0, 0, 0, 0, 0};
            rotation270.push_back(
                    std::vector<int>(line270_0_N, line270_0_N + sizeof line270_0_N / sizeof line270_0_N[0]));
            rotation270.push_back(
                    std::vector<int>(line270_1_N, line270_1_N + sizeof line270_1_N / sizeof line270_1_N[0]));
            rotation270.push_back(
                    std::vector<int>(line270_2_N, line270_2_N + sizeof line270_2_N / sizeof line270_2_N[0]));
            rotation270.push_back(
                    std::vector<int>(line270_3_N, line270_3_N + sizeof line270_3_N / sizeof line270_3_N[0]));
            rotation270.push_back(
                    std::vector<int>(line270_4_N, line270_4_N + sizeof line270_4_N / sizeof line270_4_N[0]));
        }
            break;
        case N_mirrored: {
            int line0_0_N_mirrored[] = {0, 0, 0, 0, 0};
            int line0_1_N_mirrored[] = {0, 0, 1, 0, 0};
            int line0_2_N_mirrored[] = {0, 0, 2, 1, 0};
            int line0_3_N_mirrored[] = {0, 0, 0, 1, 0};
            int line0_4_N_mirrored[] = {0, 0, 0, 0, 0};
            rotation0.push_back(std::vector<int>(line0_0_N_mirrored, line0_0_N_mirrored + sizeof line0_0_N_mirrored /
                                                                                          sizeof line0_0_N_mirrored[0]));
            rotation0.push_back(std::vector<int>(line0_1_N_mirrored, line0_1_N_mirrored + sizeof line0_1_N_mirrored /
                                                                                          sizeof line0_1_N_mirrored[0]));
            rotation0.push_back(std::vector<int>(line0_2_N_mirrored, line0_2_N_mirrored + sizeof line0_2_N_mirrored /
                                                                                          sizeof line0_2_N_mirrored[0]));
            rotation0.push_back(std::vector<int>(line0_3_N_mirrored, line0_3_N_mirrored + sizeof line0_3_N_mirrored /
                                                                                          sizeof line0_3_N_mirrored[0]));
            rotation0.push_back(std::vector<int>(line0_4_N_mirrored, line0_4_N_mirrored + sizeof line0_4_N_mirrored /
                                                                                          sizeof line0_4_N_mirrored[0]));

            int line90_0_N_mirrored[] = {0, 0, 0, 0, 0};
            int line90_1_N_mirrored[] = {0, 0, 0, 0, 0};
            int line90_2_N_mirrored[] = {0, 0, 2, 1, 0};
            int line90_3_N_mirrored[] = {0, 1, 1, 0, 0};
            int line90_4_N_mirrored[] = {0, 0, 0, 0, 0};
            rotation90.push_back(std::vector<int>(line90_0_N_mirrored, line90_0_N_mirrored +
                                                                       sizeof line90_0_N_mirrored /
                                                                       sizeof line90_0_N_mirrored[0]));
            rotation90.push_back(std::vector<int>(line90_1_N_mirrored, line90_1_N_mirrored +
                                                                       sizeof line90_1_N_mirrored /
                                                                       sizeof line90_1_N_mirrored[0]));
            rotation90.push_back(std::vector<int>(line90_2_N_mirrored, line90_2_N_mirrored +
                                                                       sizeof line90_2_N_mirrored /
                                                                       sizeof line90_2_N_mirrored[0]));
            rotation90.push_back(std::vector<int>(line90_3_N_mirrored, line90_3_N_mirrored +
                                                                       sizeof line90_3_N_mirrored /
                                                                       sizeof line90_3_N_mirrored[0]));
            rotation90.push_back(std::vector<int>(line90_4_N_mirrored, line90_4_N_mirrored +
                                                                       sizeof line90_4_N_mirrored /
                                                                       sizeof line90_4_N_mirrored[0]));

            int line180_0_N_mirrored[] = {0, 0, 0, 0, 0};
            int line180_1_N_mirrored[] = {0, 1, 0, 0, 0};
            int line180_2_N_mirrored[] = {0, 1, 2, 0, 0};
            int line180_3_N_mirrored[] = {0, 0, 1, 0, 0};
            int line180_4_N_mirrored[] = {0, 0, 0, 0, 0};
            rotation180.push_back(std::vector<int>(line180_0_N_mirrored, line180_0_N_mirrored +
                                                                         sizeof line180_0_N_mirrored /
                                                                         sizeof line180_0_N_mirrored[0]));
            rotation180.push_back(std::vector<int>(line180_1_N_mirrored, line180_1_N_mirrored +
                                                                         sizeof line180_1_N_mirrored /
                                                                         sizeof line180_1_N_mirrored[0]));
            rotation180.push_back(std::vector<int>(line180_2_N_mirrored, line180_2_N_mirrored +
                                                                         sizeof line180_2_N_mirrored /
                                                                         sizeof line180_2_N_mirrored[0]));
            rotation180.push_back(std::vector<int>(line180_3_N_mirrored, line180_3_N_mirrored +
                                                                         sizeof line180_3_N_mirrored /
                                                                         sizeof line180_3_N_mirrored[0]));
            rotation180.push_back(std::vector<int>(line180_4_N_mirrored, line180_4_N_mirrored +
                                                                         sizeof line180_4_N_mirrored /
                                                                         sizeof line180_4_N_mirrored[0]));

            int line270_0_N_mirrored[] = {0, 0, 0, 0, 0};
            int line270_1_N_mirrored[] = {0, 0, 1, 1, 0};
            int line270_2_N_mirrored[] = {0, 1, 2, 0, 0};
            int line270_3_N_mirrored[] = {0, 0, 0, 0, 0};
            int line270_4_N_mirrored[] = {0, 0, 0, 0, 0};
            rotation270.push_back(std::vector<int>(line270_0_N_mirrored, line270_0_N_mirrored +
                                                                         sizeof line270_0_N_mirrored /
                                                                         sizeof line270_0_N_mirrored[0]));
            rotation270.push_back(std::vector<int>(line270_1_N_mirrored, line270_1_N_mirrored +
                                                                         sizeof line270_1_N_mirrored /
                                                                         sizeof line270_1_N_mirrored[0]));
            rotation270.push_back(std::vector<int>(line270_2_N_mirrored, line270_2_N_mirrored +
                                                                         sizeof line270_2_N_mirrored /
                                                                         sizeof line270_2_N_mirrored[0]));
            rotation270.push_back(std::vector<int>(line270_3_N_mirrored, line270_3_N_mirrored +
                                                                         sizeof line270_3_N_mirrored /
                                                                         sizeof line270_3_N_mirrored[0]));
            rotation270.push_back(std::vector<int>(line270_4_N_mirrored, line270_4_N_mirrored +
                                                                         sizeof line270_4_N_mirrored /
                                                                         sizeof line270_4_N_mirrored[0]));
        }
            break;
        case T: {
            int line0_0_T[] = {0, 0, 0, 0, 0};
            int line0_1_T[] = {0, 0, 1, 0, 0};
            int line0_2_T[] = {0, 0, 2, 1, 0};
            int line0_3_T[] = {0, 0, 1, 0, 0};
            int line0_4_T[] = {0, 0, 0, 0, 0};
            rotation0.push_back(std::vector<int>(line0_0_T, line0_0_T + sizeof line0_0_T / sizeof line0_0_T[0]));
            rotation0.push_back(std::vector<int>(line0_1_T, line0_1_T + sizeof line0_1_T / sizeof line0_1_T[0]));
            rotation0.push_back(std::vector<int>(line0_2_T, line0_2_T + sizeof line0_2_T / sizeof line0_2_T[0]));
            rotation0.push_back(std::vector<int>(line0_3_T, line0_3_T + sizeof line0_3_T / sizeof line0_3_T[0]));
            rotation0.push_back(std::vector<int>(line0_4_T, line0_4_T + sizeof line0_4_T / sizeof line0_4_T[0]));

            int line90_0_T[] = {0, 0, 0, 0, 0};
            int line90_1_T[] = {0, 0, 0, 0, 0};
            int line90_2_T[] = {0, 1, 2, 1, 0};
            int line90_3_T[] = {0, 0, 1, 0, 0};
            int line90_4_T[] = {0, 0, 0, 0, 0};
            rotation90.push_back(std::vector<int>(line90_0_T, line90_0_T + sizeof line90_0_T / sizeof line90_0_T[0]));
            rotation90.push_back(std::vector<int>(line90_1_T, line90_1_T + sizeof line90_1_T / sizeof line90_1_T[0]));
            rotation90.push_back(std::vector<int>(line90_2_T, line90_2_T + sizeof line90_2_T / sizeof line90_2_T[0]));
            rotation90.push_back(std::vector<int>(line90_3_T, line90_3_T + sizeof line90_3_T / sizeof line90_3_T[0]));
            rotation90.push_back(std::vector<int>(line90_4_T, line90_4_T + sizeof line90_4_T / sizeof line90_4_T[0]));

            int line180_0_T[] = {0, 0, 0, 0, 0};
            int line180_1_T[] = {0, 0, 1, 0, 0};
            int line180_2_T[] = {0, 1, 2, 0, 0};
            int line180_3_T[] = {0, 0, 1, 0, 0};
            int line180_4_T[] = {0, 0, 0, 0, 0};
            rotation180.push_back(
                    std::vector<int>(line180_0_T, line180_0_T + sizeof line180_0_T / sizeof line180_0_T[0]));
            rotation180.push_back(
                    std::vector<int>(line180_1_T, line180_1_T + sizeof line180_1_T / sizeof line180_1_T[0]));
            rotation180.push_back(
                    std::vector<int>(line180_2_T, line180_2_T + sizeof line180_2_T / sizeof line180_2_T[0]));
            rotation180.push_back(
                    std::vector<int>(line180_3_T, line180_3_T + sizeof line180_3_T / sizeof line180_3_T[0]));
            rotation180.push_back(
                    std::vector<int>(line180_4_T, line180_4_T + sizeof line180_4_T / sizeof line180_4_T[0]));

            int line270_0_T[] = {0, 0, 0, 0, 0};
            int line270_1_T[] = {0, 0, 1, 0, 0};
            int line270_2_T[] = {0, 1, 2, 1, 0};
            int line270_3_T[] = {0, 0, 0, 0, 0};
            int line270_4_T[] = {0, 0, 0, 0, 0};
            rotation270.push_back(
                    std::vector<int>(line270_0_T, line270_0_T + sizeof line270_0_T / sizeof line270_0_T[0]));
            rotation270.push_back(
                    std::vector<int>(line270_1_T, line270_1_T + sizeof line270_1_T / sizeof line270_1_T[0]));
            rotation270.push_back(
                    std::vector<int>(line270_2_T, line270_2_T + sizeof line270_2_T / sizeof line270_2_T[0]));
            rotation270.push_back(
                    std::vector<int>(line270_3_T, line270_3_T + sizeof line270_3_T / sizeof line270_3_T[0]));
            rotation270.push_back(
                    std::vector<int>(line270_4_T, line270_4_T + sizeof line270_4_T / sizeof line270_4_T[0]));
        }
            break;
    }

    ColorName color = ColorPalette::getInstance()->getRandomColor();

    return Piece(rotation0, rotation90, rotation180, rotation270, current_rotation, type, color);

}