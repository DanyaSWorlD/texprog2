#include "stdafx.h"
#include "../texprog2/Semaphore.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TexProg2Tests
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;
	public: 
		/// <summary>
		///Получает или устанавливает контекст теста, в котором предоставляются
		///сведения о текущем тестовом запуске и обеспечивается его функциональность.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//При написании тестов можно использовать следующие дополнительные атрибуты:
		//
		//ClassInitialize используется для выполнения кода до запуска первого теста в классе
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//ClassCleanup используется для выполнения кода после завершения работы всех тестов в классе
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//TestInitialize используется для выполнения кода перед запуском каждого теста
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//TestCleanup используется для выполнения кода после завершения каждого теста
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 
		//Тело теста 
		void TestBody(int threads, int semaphore, int wt)
		{
			Test test;
			test.abort_thread = 0;

			Semaphore test_sm(semaphore);


			HANDLE *h = new HANDLE[threads];
			DWORD id;
			for (int i = 0; i < threads; i++)
			{
				h[i] = CreateThread(NULL, 0, test.testFunc, &test_sm, 0, &id);
			}

			Sleep(wt);

			test.abort_thread = 1;
			WaitForMultipleObjects(threads, h, TRUE, INFINITY);

			delete h;
		}
		///Тест 10 потоков. Пропускная способность семафора - 2. Время ожидания 1000
		[TestMethod]
		void Th10S2T1000()
		{
			TestBody(10, 2, 1000);
		};
		///Тест 100 потоков. Пропускная способность семафора - 2. Время ожидания 10000
		[TestMethod]
		void Th100S2T10000()
		{
			TestBody(100, 2, 10000);
		};
		///Тест 5 потоков. Пропускная способность семафора - 1. Время ожидания 1000
		[TestMethod]
		void Th5S1T1000()
		{
			TestBody(5, 1, 1000);
		};
		///Тест 1000 потоков. Пропускная способность семафора - 2. Время ожидания 1000000
		[TestMethod]
		void Th1000S2T1000000()
		{
			TestBody(1000, 2, 1000000);
		};
		///Тест 100 потоков. Пропускная способность семафора - 10. Время ожидания 1000000
		[TestMethod]
		void Th100S10T1000000()
		{
			TestBody(100, 10, 1000000);
		};
	};
}
