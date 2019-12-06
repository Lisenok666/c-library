#pragma once

typedef int(*TEST)(void);

void init_tests();

void deinit_tests();

int run_all_tests();

void run_test(int num, char* description, TEST test);

int test_create(void);

int test_add(void);

int test_remove(void);

