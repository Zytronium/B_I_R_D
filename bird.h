//
// Created by Anonymous on 7/19/2024.
//

#ifndef BIRD_H
#define BIRD_H

typedef struct bird_system_s {
	void (*activate)(int, const int *);

	void (*detonate)(float);
} bird_system_t; // TODO: Change these 2 pointers because they only apply to one system


bird_system_t *self_destruct_system;

int initSelfDestrSys(void);

#endif //BIRD_H
