Моё приложение было разработано с помощью Qt Creator 4.11.1 (Based on Qt 5.14.1).
Я выбрал эту среду разработки, так как уже работал с ней на первом курсе во втором семестре.

Этапы разработки:
1) "Набросок" дизайна интерфейса
2) Реализация всей математики(переводов)
3) Окончательный дизайн, добавления функционала(кнопок)

Разработанное приложение включает в себя 2 класса:

1) Mainwindow - класс, в котором описаны интерфейс и функционал приложения.
Разрешение - 640x360.
В приложении можно выбрать любой из 18-ти вариантов работы.
Нажатие по квадрату цвета или кнопке "Choose color" вызовет
стандартное диалоговое окно выбора цвета.
Ввод HEX-значения цвета в соответствующую строку(ввод чего-либо кроме числа,
в HEX-виде запрещен)
Все цветовые модели(кроме RGB) имеют точность до 3-х знаков после запятой.

2) Math - класс, название которого отраражет причину его создания: он используеться для хранения
значений цвета во всех цветовых моделях.
Set-методы, устанавливающие новые значения для 1 из моделей,
автоматический пересчитавают значения цвета для других моделей.
При некорректности перевода, к примеру из XYZ в RGB, при выходе
значений за допустимые граница (для RGB [0,255]), класс автоматически
округлит значения до ближайшей границы. 
Класс содержит численные представления во всех 6 моделях(RGB,CMYK,
HSL,HSV,XYZ,LAB) и значение цвета в HEX-виде.

Примечание:
-на данный момент(вечер пятницы 30.09) есть ошибка с системой HSV, всё остальное переводится корректно
-в архиве lab1 лежит рабочий .exe-файл и необходимые библиотеки.
-на всякий случай, моя почта: varenik_a003@mail.ru

