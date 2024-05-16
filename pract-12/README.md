**Задача 1.** Реализирайте темплейтен клас **Vector**, който има минимум следните функции:

[**push_back**](https://cplusplus.com/reference/vector/vector/push_back/) - добавя елемент в края на вектора (да може и да се прави копие на подадения обект, и да се откраднат данните му)<br />
[**pop_back**](https://cplusplus.com/reference/vector/vector/pop_back/) - изтрива последния елемент на вектора<br />
[**insert**](https://cplusplus.com/reference/vector/vector/insert/) - добавя елемент на даден индекс във вектора<br />
[**erase**](https://cplusplus.com/reference/vector/vector/erase/) - изтрива елемент на даден индекс във вектора<br />
[**clear**](https://cplusplus.com/reference/vector/vector/clear/) - изчиства данните във вектора<br />


**Задача 2.**  Windows forms е UI framework за лесно създаване на приложения за windows. Той
представя лесен начин за създаване на приложения графично и се поддържа от езикци като C#. Приложенията представляват множество от форми, в които има контроли.
Да се създаде клас, който представя **Форма**. Формата има размер (широчина и дължина) и име. Всяка форма поддържа колекция от контроли.

Всеки **контрол** има размер и локация във формата. Също така, всеки контрол има функция `setDataDialog();`, която позволява на потребителя да промени контрола по подходящ начин. Всеки контрол може да променя размерите си. Имаме следните контроли:

1. *TextBox* - Контрол, в който се подава текст. `setDataDialog()` променя текста му.
![check](https://i.stack.imgur.com/AhOpr.jpg)
3. *CheckBox* - Контрол, който има текст и състояние (включен или изключен).
    `setDataDialog()` променя дали е включен или изключен по подразбиране. За промяна на текста може да добавите допълнителна функция.
    ![radio](https://images.theengineeringprojects.com/image/main/2017/10/C-CheckBox-9.png)
    
4. *RadioButton* - Контрол, който има няколко опции, но само една е избрана.
    `setDataDialog()` променя избраната опция. Може да добавите допълнителна логика за промяната на опциите. Броят им, веднъж зададен, не се променя.
    ![radio](https://i.stack.imgur.com/EyNQT.png)

Реализирайте хетерогенен контейнер, който съдържа различните контроли, които вашата форма притежава. 
Трябва да имате следните методи:
- метод за добавяне на контрола към контейнера
- метод за променяне на размера на формата, както и на всеки от контролите (може да достъпвате контролите по индекс)
- функция за промяна на локацията на контролите, като те не трябва да излизат извън формата
- метод `change(size_t index);` който променя контрола на подадения индекс. Промяната става чрез извикване на `setDataDialog` функцията на съответния контрол.
