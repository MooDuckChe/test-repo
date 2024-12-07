#include <vector>
#include <functional>
#include <iostream>

//#include "tests.h" Autotests?
// The Test that makes code the unusual behavior?
#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

//Test body_contains inside green candle
bool test1()
{
  Candle candle_green{0, 20, -5, 12};

  return candle_green.body_contains(10);
}

//Test body_contains inside red candle
bool test2()
{
  Candle candle_red{10, 40, -3, -2};

  return candle_red.contains(2);
}

//Test body_contains inside candle with zero
bool test3()
{
  Candle candle{0.0, 0.0, 0.0, 0.0};

  return candle.body_contains(0);
}

// Test contains inside green candle
bool test4()
{
  Candle candle{0.0, 100, -100, 4.0};

  return candle.contains(0.1);
}

// Test contains outside green candle
bool test5()
{
  Candle candle{0.0, 100, -100, 4.0};

  return candle.contains(-100.1) == false;
}

// Test contains in green shadow
bool test6()
{
  Candle candle{0.0, 100, -100, 4.0};

  return candle.contains(100);
}

// Test full_size 
bool test7()
{
  Candle candle{0.0, 100, -100, 4.0};

  return candle.full_size() == 200;
}

// Test full_size with zero
bool test8()
{
  Candle candle{0.0, 0, 0, 0.0};

  return candle.full_size() == 0.0;
}

// Test full_size with large positive nums
bool test9()
{
  Candle candle{0.0, 1.0, 1e99, 0.0};
  
  return candle.full_size() == 1e+99;
}

// Test body_size with zero candle 
bool test10()
{
  Candle candle_green{0.0, 0.0, 0.0, 0.0};

  return candle_green.body_size() == 0.0;
}

// Test body_size with red candle
bool test11()
{
  Candle candle_red{0.0, 0.0, 0.0, -1123.0};

  return candle_red.body_size() == 1123.0;
}

// Test body_size with green candle
bool test12()
{
  Candle candle_green{128.0, 0.0, 0.0, 1024.0};

  return candle_green.body_size() == 896;
}

// Test is_green with zero candle 
bool test13()
{
  Candle candle_green{0.0, 0.0, 0.0, 0.0};

  return candle_green.is_green() == false;
}

// Test is_green with red candle
bool test14()
{
  Candle candle_red{0.0, 0.0, 0.0, 1.0};

  return candle_red.is_green() == true;
}

// Test is_green with green candle
bool test15()
{
  Candle candle_green{-1.0, 0.0, 0.0, -10.0};

  return candle_green.is_green() == false;
}

void initTests()
{
  tests.push_back(test1);
  tests.push_back(test2);
  tests.push_back(test3);
  tests.push_back(test4);
  tests.push_back(test5);
  tests.push_back(test6);
  tests.push_back(test7);
  tests.push_back(test8);
  tests.push_back(test9);
  tests.push_back(test10);
  tests.push_back(test11);
  tests.push_back(test12);
  tests.push_back(test13);
  tests.push_back(test14);
  tests.push_back(test15);
  
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
