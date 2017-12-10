#include "Semaphore.h"


void Semaphore::Enter() ///Вход в семафор
{
	countCS.Enter(); /// Блокируем доступ из других потоков к нашим переменным
	if (Count++ < maxCount) /// Проверяем, что есть свободные места
	{
		count_dbg++; /// Увеличиваем количество потоков

		countCS.Leave(); /// Разблокируваем доступ и выходим
		return;
	}

	countCS.Leave();

	ev.Wait(); /// Ожидаем события освобождения места 


	countCS.Enter(); /// Заходим в критическую секцию для увеличения количествоа потоков, у которых есть доступ к данным
	count_dbg++; /// Увеличиваем
	countCS.Leave(); /// Выходим
}

void Semaphore::Leave()
{
	countCS.Enter();            /// Блокируем доступ из других потоков к нашим переменным
	if (--Count >= maxCount)  /// Уменьшаем количество потоков, которые получают данные
		ev.Set();            /// Если ожидаем события, то взводим его

	count_dbg--;                /// Уменьшаем количество потоков, которые получают доступ к данным


	countCS.Leave();  /// Выходим

}

DWORD WINAPI Test::testFunc(LPVOID param)  /// тестовая функция
{
	Semaphore * smp = (Semaphore *)param;  ///Указатель на семафор, через который работаем

	while (1)
	{
		if (abort_thread)  /// Остановка потока
			return 0;

		smp->Enter(); /// Вход в семафор
		auto mas = new int[1000];
		for (int i = 0; i<1000; i++) /// Цикл забива рандомными значениями
		{
			mas[i] = rand() % 1000 - 500;
		}
		bool changes = true; 
		while (changes) /// Сортировка пузырьком. Полезная нагрузка
		{
			changes = false;
			for (int i = 0; i < 999; i++)
				if (mas[i] > mas[i + 1])
				{
					int a = mas[i];
					mas[i] = mas[i + 1];
					mas[i + 1] = a;
					changes = true;
				}
			Sleep(1);
		}
		delete[] mas;
		smp->Leave();  ///Покидание семафора
	}
}