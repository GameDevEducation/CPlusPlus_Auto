#include <iostream>
#include <string>
#include <vector>

class SimpleClass
{
public:
	SimpleClass(int inData) : Data(inData)
	{

	}

	~SimpleClass()
	{
		std::cout << "Destroy " << Data << std::endl;
	}

	// auto is not permitted for parameters
	//void TestFunction(auto inputParam = 5)
	//{

	//}

	auto TestFunction2() const
	{
		return "test!";
	}

	int Data = -1;
	//auto Data2 = 5; auto is not permitted for member variables
};

int main()
{
	auto testVar1 = 42;
	testVar1 = 20;
	auto testVar2 = "test!";
	
	// testVar1 = "test"; - auto cannot change type
	std::cout << "testVar1 = " << testVar1 << std::endl;
	std::cout << "testVar2 = " << testVar2 << std::endl;

	int testInt = 42;

	// test with references
	int& testRef1 = testInt;
	++testRef1;

	std::cout << "testInt = " << testInt << " testRef = " << testRef1 << std::endl;

	auto testAuto3 = testRef1; // this will do a copy by value (it is not a reference)
	++testAuto3;

	std::cout << "testInt = " << testInt << " testRef = " << testRef1 << " testAuto3 = " << testAuto3 << std::endl;

	auto& testAuto4 = testInt; // this will be a reference to testInt
	++testAuto4;

	std::cout << "testInt = " << testInt << " testRef = " << testRef1 << " testAuto4 = " << testAuto4 << std::endl;

	// test with pointers
	int* testPtr1 = &testInt;
	++(*testPtr1);

	std::cout << "testInt = " << testInt << " testPtr1 = " << *testPtr1 << std::endl;

	auto testAuto5 = testPtr1;
	++(*testAuto5);

	std::cout << "testInt = " << testInt << " testPtr1 = " << *testPtr1 << " testAuto5 = " << *testAuto5 << std::endl;

	// test with loops
	std::vector<SimpleClass> dataSet1;
	dataSet1.reserve(5);
	dataSet1.emplace_back(1);
	dataSet1.emplace_back(2);
	dataSet1.emplace_back(3);
	dataSet1.emplace_back(4);
	dataSet1.emplace_back(5);

	const auto& dataSet2 = dataSet1;

	for (const auto& data : dataSet1)
	{
		std::cout << "Data is " << data.Data << std::endl;
		std::cout << data.TestFunction2() << std::endl;
	}

	//for (std::vector<SimpleClass>::iterator dataIt; dataIt != dataSet1.end(); ++dataIt)
	for (auto dataIt = dataSet1.begin(); dataIt != dataSet1.end(); ++dataIt)
	{
		std::cout << "Data is " << (*dataIt).Data << std::endl;
	}
}
