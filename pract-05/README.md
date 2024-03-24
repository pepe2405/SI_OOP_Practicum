## Задача 1

Да се реализира проста система за купуване и продаване на различни продукти.

1. Клас представящ потребител (User).
    * Член-данни:
        - ```size_t``` id - Индекс на потребителя. Никой потребител няма id = 0.
        - ```char[32]``` name - Име с дължина 32 символа.
        - ```double``` balance - Парите с които разполага.
    * Класът трябва да има:
      - Конструктор по подразбиране (слагат се default стойности на член-данните като id = 0).
      - Конструктор с параметри.
      - ```void``` updateMoney(double amount); - Добавя ```amount``` към парите. Парите не могат да бъдат отрицателни
      - ```bool``` hasMoney(double amount);       - Връща дали потребителя има достатъчно пари.
      - ```size_t``` getID                     - Връща индекса на потребителя

1. Клас представляващ продукс (Product):
   * Член-данни:
     - ```char[32]``` name - Име на продукта.
     - ```size_t``` ownerId - id на притежателя му.
     - ```size_t``` quantity - Колко бройки от този продукт притежаваме
     - ```size_t``` productId - Индекс на продукта. Никой продукт няма индекс 0.
   * Класът трябва да има:
     - Конструктор по подразбиране.
     - Конструктор с параметри
     - ```size_t``` getQuantity - връща колко бройки има.
     - ```void``` updateQuantity(int amount) - променя броя на продуктите. Броя на продуктите никога не е по - малък от 0.
     - ```size_t``` getProductID - връща индекса на продукта
     - ```size_t``` getOwnerID - връща индекса на притежателя.

2. Клас пазещ цените на продуктите (Price):
   * Член-данни:
     - ```size_t``` productId - Индекс на продуктът.
     - ```double``` price     - Цена
   * Класът трябва да има:
     - Конструктор по подразбиране. Отново слага productId = 0.
     - Конструктор с параметри.
     - ```double``` getPrice - Връща цената.
     - ```size_t``` getId    - Връща productId
     - ```void``` updatePrice(double amount) - Добавя amount към price. Не може да е отрицателно число
       
3. Клас, пазещ информация за потребителите в системата (UsersDatabase):
   * Член-данни
     - ```user[50]``` users - Статичен масив пазещ всички потребители
     - ```size_t``` size   - Броя на потребителите до момента
   * Класът трябва да има:
     - Конструктор по подразбиране - създава празна база.
     - ```void``` addUser - Добавя потребител в базата. Всеки потребител в базата има **уникално** id. Ако потребителите станат повече от капацитета се изтрива първия въведен потребител.
     - ```bool``` hasEnoughMoney(id, money) - проверява дали потребител с този индекс има достатъчно пари.
     - Други помощни функции (bool existUser...)

4. Клас, пазещ информация за продуктите в системата (ProductsDatabase):
   * Член-данни
     - ```Product[50]``` products - Статичен масив пазещ всички потребители
     - ```size_t``` size   - Броя на потребителите до момента
   * Класът трябва да има:
     - Конструктор по подразбиране - създава празна база.
     - ```void``` addProduct(name, id, prodID, quantity) - Добавя продукт в базата. Всеки продукт в базата има **уникално** productId. ID-то на потребителя се приема като аргумент. Ако продуктите станат повече от капацитета се изтрива първия въведен продукт.
     - ```size_t``` itemsOwned(id, productID) - връща колко бройки от даден продукт притежава даден потребител.
     - ```void``` update(id, productID, update) - променя колко бройки притежава даден потребител (в случай че продаде нещо или купи)
     - Други помощни функции (existProduct...)

5. Клас, пазещ информация цените на продуктите (PricesDatabase):
   * Член-данни
     - ```price[50]``` prices - Статичен масив пазещ всички цена
     - ```size_t``` size   - Броя на цени до момента
   * Класът трябва да има:
     - Конструктор по подразбиране - създава празна база.
     - ```void``` addPrice - Добавя цена в базата. Ако цените станат повече от капацитета се изтрива първия въведената цена.
     - ```double``` getPrice(id) - Връща цената на продукт по подадено id.

6. Използвайки тези класове ще реализираме клас SalesSystem.
   * Член-данни:
     - ```UsersDatabase``` users - Пази информация за потребителите в системата.
     - ```ProductsDatabase``` products - Пази информация за продуктите в системата.
     - ```PricesDatabase``` prices - Пази информация за цените на продуктите в системата.
   * Класът трябва да поддържа:
     - Конструктор по подразбиране - създава празна система.
     - Функция за добавяне на потребител в базата.
     - Функция за добавяне на продукт в базата.
     - Няма как да добавим продукт ако той няма собственик. 
     - Функция за добавяне на цена на продукт в базата. Цената няма как да е отрицателна. Няма смисъл да пазим цени за които няма продукти. 

И най - важната функция, тази чрез която продаваме:

``` void sell(size_t idFrom, size_t idTo, size_t productID, size_t quantity) ```

Ако за продукта няма цена цената му се приема за 0.

Парите се въртят по стандартния начин. Потребителя който купува губи цената на продукта * броя на продукта.
Симетрично, този който продава печели същата сума.

В базата данни за продуктите броя на притежаваните от продавача продукти се намаля а броя на притежаваните от купувача продукти се уваличава (ако съществува. Ако не се добавя).