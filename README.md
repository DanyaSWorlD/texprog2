Лабораторная работа №2 (технология программирования)
=====================
Задание:
-----------------------------------
Реализовать класс синхронизации семафор, действующий аналогично объекту [Semaphore Windows API](https://msdn.microsoft.com/en-us/library/windows/desktop/ms685129%28v=vs.85%29.aspx). Класс инкапсулирует работу объекта синхронизации, который содержит счетчик между нулем и заданным максимальным значением. Значение счетчика увеличивается каждый раз, когда поток завершает ожидание освобождения семафора, и уменьшается, когда поток освобождает семафор. В случае, если значение счетчика достигает максимального значения, потоки ожидают освобождение семафора. Если указано максимальное значение счетчика, равное 1, то семафор функционально должен вести себя как критическая секция (critical section).

Краткая информация:
----------------------------------- 
Семафор - механизм предоставления доступа к некоторым данным определенному количеству потоков.
Критическая секция — объект синхронизации потоков, позволяющий предотвратить одновременное выполнение некоторого набора операций (обычно связанных с доступом к данным) несколькими потоками. Критическая секция выполняет те же задачи, что и мьютекс. 
Для создания события необходимо использовать функцию CreateEvent которая имеет параметр ManualReset. Если этот параметр находится в состоянии False, то событие будет сбрасываться после того, как какой либо поток прошел через Event.Wait, в состоянии True - иначе.

Литература:
-----------------------------------
Рекомендуемая среда разработки Microsoft Visual Studio 2015, 
[Semaphore](https://msdn.microsoft.com/ru-ru/library/system.threading.semaphore.aspx),
[Event Objects](https://msdn.microsoft.com/ru-ru/library/ms182470.aspx),
[Critical Section Objects](https://msdn.microsoft.com/en-us/library/windows/desktop/ms682530.aspx),
[Start tests](https://msdn.microsoft.com/en-us/library/windows/desktop/ms682655.aspx).


 Авторы: 
-----------------------------------
[Голубев Никита](https://github.com/Trakerr), [Миренский Даниил](https://github.com/DanyaSWorlD), [Снегов Петр](https://github.com/sneg061).
