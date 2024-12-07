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


void initTests()
{
  tests.push_back(test1);
  tests.push_back(test2);
  tests.push_back(test3);
  tests.push_back(test4);
  tests.push_back(test5);
  tests.push_back(test6);
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
