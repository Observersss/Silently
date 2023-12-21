# Silently
 First project


## Проект: Silently



#### Майбутні оновлення

1. **Зберігання та Зчитування Даних**
    - Розробка механізму зберігання та зчитування даних для забезпечення продовження роботи зі збереженими даними.

2. **Оптимізація Роботи з Дедлайном**
    - Поглиблене вивчення та реалізація функціоналу дедлайнів, надання їм більшої функціональності та коректної роботи.

3. **Поліпшення GUI**
    - Налаштування та оновлення інтерфейсу користувача з метою поліпшення його зовнішнього вигляду та функціональності.

4. **Додавання Посилань на Нотатки**
    - Можливість приєднання посилань на нотатки, які створені в NoteSpace, до кожного квесту для зручності користувача.

5. **Розробка Toolbar**
    - Створення та додавання Toolbar для забезпечення швидкого доступу до основних функцій та операцій.

6. **Система Повідомлень**
    - Реалізація системи повідомлень для сповіщення користувача про події, оновлення та важливі повідомлення.

7. **Візуальний Гайд для Користувача**
    - Підготовка та створення візуального гайду для кращого розуміння та навігації користувача в програмі.

8. **Пасхалки та Візуальні Елементи**
    - Додавання схованих предметів та міні-ігор для розваги та цікавості користувачів.

Ці оновлення будуть поступово реалізовані в майбутніх версіях проекту для поліпшення його функціональності та зручності користування.

# Опис основних секцій програми
## RPG-space

## Опис файлу LIBRARY_H

Цей файл `LIBRARY_H` містить список включених бібліотек у  проекті.

### Включені бібліотеки

1. **iostream**: Використовується для введення та виведення даних у консоль.
2. **vector**: Містить реалізацію динамічного масиву.
3. **string** та **QString**: Робота з рядками символів.
4. **QPixmap**: Клас для роботи з зображеннями та графікою в Qt.
5. **chrono** та **ctime**: Робота з часом та датами.
6. **QRandomGenerator**: Генерування випадкових чисел у Qt.
7. **QMessageBox**: Використовується для показу діалогових вікон повідомлень.
8. **QDateTimeEdit**: Дозволяє редагувати дату та час.
9. **QListWidget**: Елемент для відображення списків у Qt.
10. **algorithm**: Містить реалізації різноманітних алгоритмів.
11. **map**: Асоціативний контейнер, що містить пари ключ-значення.

//include <QTimer>: Якщо необхідно, розкоментуйте для включення QTimer.


#### Клас Item

##### Опис
`Item` представляє предмет у грі з певними характеристиками, рангом, назвою, описом та зображенням.

##### Публічні методи

- `Item()`: Конструктор класу, створює новий предмет з випадковими характеристиками, рангом, назвою та зображенням.

- `QString getRank()const`: Повертає ранг предмету.

- `QString getnameOfitem()const`: Повертає назву предмету.

- `QString getdiscriptionOfItem()const`: Повертає опис предмету.

- `std::vector<std::pair<QString, int>> getCharacteristics()const`: Повертає вектор з характеристиками предмету.

- `Equipment getTypeItem()const`: Повертає тип предмету.

- `QPixmap getImageOfItem() const`: Повертає зображення предмету.

- `int getIndex()const`: Повертає індекс предмету.

##### Публічні функції-члени

- `void setName(QString name)`: Задає назву предмету.

- `void setDiscription(QString discription)`: Задає опис предмету.

- `void setCharacteristics(QString nameCharacteristic,double value)`: Задає характеристику предмету.

- `void setEqipment(Equipment type)`: Задає тип предмету.

- `void setImage(QString name)`: Задає зображення предмету.

##### Приватні члени

- `QString rank`: Ранг предмету.

- `QString nameOfItem`: Назва предмету.

- `QString discriptionOfItem`: Опис предмету.

- `std::vector<std::pair<QString, int>> Characteristics`: Вектор з характеристиками предмету.

- `Equipment typeItem`: Тип предмету.

- `QPixmap imageOfItem`: Зображення предмету.

- `static int itemCount`: Статична змінна для підрахунку кількості предметів.

- `int index`: Індекс предмету.

- `static std::map<QString, QString> itemImages_`: Мапа з шляхами до зображень предметів.

##### Приклад використання

```cpp
// Створення нового предмету
Item sword;
```



#### Клас Inventory

##### Опис
`Inventory` представляє інвентар користувача у грі, де зберігаються предмети та активне спорядження.

##### Публічні методи

- `Inventory()`: Конструктор класу, створює новий інвентар.

- `void addItemInInventory(Item item)`: Додає предмет до інвентаря.

- `void deleteItemInInventory(Item item)`: Видаляє предмет з інвентаря.

- `void deleteItemEuipment(Item item)`: Видаляє предмет з активного спорядження.

- `void addToEquipment(const Item& item)`: Додає предмет до активного спорядження.

- `void removeFromEquipment(Item item)`: Знімає предмет з активного спорядження та повертає його в інвентар.

- `std::vector<Item> getItemInInventory() const`: Повертає вектор з усіма предметами у інвентарі.

- `std::vector<Item> getItemEquipment() const`: Повертає вектор з активним спорядженням.

- `size_t getItemInInventoryCount() const`: Повертає кількість предметів у інвентарі.

- `size_t getItemInEquipCount() const`: Повертає кількість предметів у активному спорядженні.

- `const Item& getItemAtIndex(size_t index) const`: Повертає предмет за вказаним індексом.

- `auto begin()`: Повертає ітератор початку вектора інвентаря.

- `auto end()`: Повертає ітератор кінця вектора інвентаря.

##### Приватні члени

- `std::vector<Item> itemInInventory`: Вектор предметів у інвентарі.

- `std::vector<Item> itemEquipment`: Вектор активного спорядження.

##### Приклад використання

```cpp
// Створення нового інвентаря
Inventory userInventory;

// Додавання предмету в інвентар
Item sword;
userInventory.addItemInInventory(sword);

// Додавання предмету в активне спорядження
Item shield;
userInventory.addToEquipment(shield);
```


#### Клас Quest

##### Опис
`Quest` представляє завдання в грі, яке має назву, опис, складність та дедлайн для виконання.

##### Публічні методи

- `Quest()`: Конструктор класу, створює нове завдання зі стандартними параметрами.

- `bool checkDeadline()const`: Перевіряє, чи пройшов дедлайн завдання.

- `void setTitle(QString newTitle)`: Задає назву завдання.

- `void setDiscription(QString newDiscription)`: Задає опис завдання.

- `void setDifficulti(int newDifficulty)`: Задає складність завдання.

- `void setDeadline(std::chrono::system_clock::time_point newDeadline)`: Задає дедлайн для завдання.

- `QString getTitle()const`: Повертає назву завдання.

- `QString getDiscription()const`: Повертає опис завдання.

- `int getDifficulty()const`: Повертає складність завдання.

- `std::chrono::system_clock::time_point getDeadline()const`: Повертає дедлайн завдання.

##### Приватні члени

- `QString title`: Назва завдання.

- `QString discription`: Опис завдання.

- `int difficulty`: Складність завдання.

- `std::chrono::system_clock::time_point deadline`: Дедлайн завдання.

##### Приклад використання

```cpp
// Створення нового завдання
Quest mainQuest;

// Задання назви та опису
mainQuest.setTitle("Головне завдання");
mainQuest.setDiscription("Виконати серію завдань для завершення гри");

// Задання складності та дедлайну
mainQuest.setDifficulti(5); // Наприклад, 5 - це складність завдання
auto deadline = std::chrono::system_clock::now() + std::chrono::hours(24); // Наприклад, дедлайн через 24 години
mainQuest.setDeadline(deadline);
```



#### Клас Character

##### Опис
`Character` представляє персонажа в грі, що має основні характеристики, інвентар, а також може виконувати та управляти квестами.

##### Приватні члени

- `int health`: Здоров'я персонажа.
- `int mana`: Рівень мани персонажа.
- `int experience`: Опит персонажа.
- `int level`: Рівень персонажа.
- `int damage`: Збиток персонажа.
- `int chanceOfCriticalDamade`: Шанс критичного збитку персонажа.
- `int criticalDamage`: Критичний збиток персонажа.
- `int dexterity`: Спритність персонажа.
- `int force`: Сила персонажа.
- `int intelligence`: Інтелект персонажа.
- `int luck`: Удача персонажа.
- `Inventory inventory`: Інвентар персонажа.
- `std::vector<Quest> activeQuest`: Вектор зі створеними користувачем квестами.
- `QPixmap characterImage`: Зображення самого персонажа.

##### Публічні методи

###### Конструктори
- `Character()`: Конструктор класу, створює новий об'єкт персонажа і надає йому початкові параметри.

###### Функції для роботи з квестами
- `void addActiveQuest(Quest* quest)`: Додає новий активний квест до персонажа.
- `void deleteActiveQuest(Quest& quest)`: Видаляє активний квест з персонажа.
- `Quest findQuest(const QString& title)`: Повертає об'єкт класу `Quest` за назвою.

###### Функції для роботи з інвентарем
- `void addItemToInventory(Item item)`: Додає предмет до інвентаря.
- `void removeItemFromInventory(Item item)`: Видаляє предмет з інвентаря.
- `void setInventory(Inventory value)`: Задає новий інвентар персонажа.

###### Функції для оновлення характеристик персонажа на основі екіпірованих предметів
- `void updateCharacteristicsFromInventory()`: Оновлює характеристики персонажа на основі екіпірованих предметів.
- `void removeCharacteristicsFromUnequippedItems(const Item& item)`: Видаляє характеристики з предметів, які не екіпіровані.

###### Функції для збільшення показників характеристик персонажа
- `void increaseExperience()`: Збільшує опит персонажа.
- `void updateLevel()`: Оновлює рівень персонажа та його характеристики.
- `void increaseHealth(int amount)`: Збільшує здоров'я персонажа.
- `void increaseMana(int amount)`: Збільшує ману персонажа.
- `void increaseDamage(int amount)`: Збільшує збиток персонажа.
- `void increaseChanceOfCriticalDamade(int amount)`: Збільшує шанс критичного збитку персонажа.
- `void increaseCriticalDamage(int amount)`: Збільшує критичний збиток персонажа.
- `void increaseDexterity(int amount)`: Збільшує спритність персонажа.
- `void increaseForce(int amount)`: Збільшує силу персонажа.
- `void increaseIntelligence(int amount)`: Збільшує інтелект персонажа.
- `void increaseLuck(int amount)`: Збільшує удачу персонажа.

###### Геттери
- `int getHealth() const`: Повертає значення здоров'я персонажа.
- `int getMana() const`: Повертає значення мани персонажа.
- `int getLevel() const`: Повертає рівень персонажа.
- `int getExperience() const`: Повертає значення опиту персонажа.
- `int getDamage() const`: Повертає значення збитку персонажа.
- `int getChanceOfCriticalDamade() const`: Повертає значення шансу критичного збитку персонажа.
- `int getCriticalDamage() const`: Повертає значення критичного збитку персонажа.
- `int getDexterity() const`: Повертає значення спритності персонажа.
- `int getForce() const`: Повертає значення сили персонажа.
- `int getIntelligence() const`: Повертає значення інтелекту персонажа.
- `int getLuck() const`: Повертає значення удачі персонажа.
- `Inventory getInventory()`: Повертає інвентар персонажа.
- `std::vector<Quest> getActiveQuest()`: Повертає вектор активних квестів.

##### Приклад використання

```cpp
// Створення нового персонажа
Character mainCharacter;

// Додавання квесту та предмету до інвентаря персонажа
Quest* newQuest = new Quest();
mainCharacter.addActiveQuest(newQuest);

Item newItem;
mainCharacter.addItemToInventory(newItem);

// Оновлення характеристик персонажа з інвентаря
mainCharacter.updateCharacteristicsFromInventory();

// Збільшення опиту та оновлення рівня персонажа
mainCharacter.increaseExperience();
```

# Клас MainWindow

## Опис
Клас `MainWindow` є головним вікном програми. Цей клас відповідає за управління графічним інтерфейсом користувача та інтеракції з різними компонентами програми, такими як простір нотаток, RPG-система та інші елементи.

## Публічні методи

### `MainWindow(QWidget *parent = nullptr)`
Конструктор класу, що створює головне вікно програми.

### `~MainWindow()`
Деструктор класу `MainWindow`.

### `void addActiveQuest(Quest* quest)`
Додає активний квест до персонажа.

### `void updateInfoOnCharacter()`
Оновлює інформацію про характеристики персонажа.

### `void updateInfoOnQuest()`
Оновлює інформацію про квести.

### `void handleQuestInfoClosed()`
Обробляє закриття вікна з інформацією про квест.

### `void deleteQuest()`
Видаляє активний квест.

### `void questComplete()`
Викликається при завершенні квеста.

### `void updateCharacterEquipment(const std::vector<Item>& equipment)`
Оновлює екіпіровку персонажа згідно із змінами в інвентарі.

### `void saveInfoNote()`
Зберігає інформацію про нотатку.

### `void savePreviousCurrentNote(QListWidgetItem *previous)`
Зберігає попередню поточну нотатку.

### `void unloadInfoNote()`
Вивантажує інформацію про нотатку.

### `void createNewNoteSpace(QString nameNoteService)`
Створює новий простір нотаток з вказаною назвою.

### `void deleteNoteSpace(QString nameNoteService)`
Видаляє простір нотаток за вказаною назвою.

... (інші методи)

## Приватні слоти

(Опис приватних слотів та їх функціональність)

## Змінні класу

### `Ui::MainWindow *ui`
Вказівник на об'єкт, що представляє графічний інтерфейс головного вікна.

### `Character character`
Об'єкт, який представляє персонажа.

### `Quest quest`
Об'єкт, який представляє квест.

### `std::vector<NoteService> noteSpaces`
Вектор, який містить простори нотаток.

### `int bufferNoteId`
Буферний ідентифікатор нотатки.

### `static int noteCounter`
Лічильник для нумерації створених нотаток.

(Інші змінні та їх опис)




#### Клас `AddQuest`

##### Опис
Клас `AddQuest` відображає вікно для додавання нового квесту у гру. Воно дозволяє встановлювати назву, опис, складність та дедлайн для нового завдання.

##### Публічні методи

- `AddQuest(QWidget* parent = nullptr)`: Конструктор класу, ініціалізує вікно додавання квесту.
  
- `~AddQuest()`: Деструктор класу, звільняє пам'ять, що була виділена для об'єкту інтерфейсу додавання квесту.

##### Приватні слоти

- `on_pushButton_clicked()`: Обробляє натискання кнопки "Додати квест", збирає дані з полів вводу та створює новий квест у головному вікні гри.

- `on_pushButton_2_clicked()`: Обробляє натискання кнопки "Встановити дедлайн", відображає поле для вибору дати та часу дедлайну.

##### Приватні члени

- `Ui::AddQuest *ui`: Вказівник на об'єкт, що містить візуальні компоненти вікна додавання квесту.
  
- `Quest quest`: Об'єкт, що представляє квест, що буде створений.

##### Приклад використання

```cpp
// Створення вікна для додавання квесту
AddQuest addQuestWindow;

// Натискання кнопки "Встановити дедлайн" для вибору дати та часу дедлайну
addQuestWindow.on_pushButton_2_clicked();

// Введення даних та натискання кнопки "Додати квест" для створення нового квесту
addQuestWindow.on_pushButton_clicked();
```


#### Клас `InventoryWindow`

##### Опис
Клас `InventoryWindow` відображає вікно інвентаря персонажа. Він дозволяє користувачеві переглядати, екіпірувати, знімати екіпірування та видаляти предмети з інвентаря.

##### Публічні методи

- `InventoryWindow(QWidget *parent = nullptr, Character *playerCharacter = nullptr)`: Конструктор класу, ініціалізує вікно інвентаря з посиланням на об'єкт персонажа.
  
- `~InventoryWindow()`: Деструктор класу, звільняє пам'ять, що була виділена для об'єкту інтерфейсу інвентаря.

##### Приватні слоти

- `on_listWidget_itemClicked(QListWidgetItem *item)`: Обробляє натискання на елемент списку предметів інвентаря та відображає його характеристики.

- `on_Equip_clicked()`: Обробляє натискання кнопки "Екіпірувати", переміщає предмет з інвентаря в обладнання персонажа.

- `on_take_off_clicked()`: Обробляє натискання кнопки "Зняти", переміщає предмет з обладнання персонажа в інвентар.

- `on_Delete_clicked()`: Обробляє натискання кнопки "Видалити" у списку інвентаря та видаляє вибраний предмет.

- `on_Delete_2_clicked()`: Обробляє натискання кнопки "Видалити" у списку обладнання та видаляє вибраний предмет.

##### Приватні члени

- `Ui::InventoryWindow *ui`: Вказівник на об'єкт, що містить візуальні компоненти вікна інвентаря.
  
- `Character *character`: Посилання на об'єкт персонажа, інвентар якого відображається у вікні.

##### Приватні методи

- `addItemToListWidget(const QString &itemName, QListWidget *listWidget)`: Додає елемент у список віджетів.

- `removeItemFromListWidget(QListWidget *listWidget, int selectedIndex)`: Видаляє елемент зі списку віджетів за вказаним індексом.

- `findItemByName(const QString &itemName, const std::vector<Item> &items)`: Пошук предмета за назвою у векторі предметів.

- `updateCharacterFromInventory()`: Оновлює характеристики персонажа відповідно до інвентаря.

- `removeCharacteristicsFromItems(const std::vector<Item> &items)`: Видаляє характеристики предметів, які були вилучені з обладнання персонажа.

##### Приклад використання

```cpp
// Створення вікна інвентаря для конкретного персонажа
Character playerCharacter;
InventoryWindow inventoryWindow(nullptr, &playerCharacter);

// Натискання на предмет у списку інвентаря для відображення його характеристик
inventoryWindow.on_listWidget_itemClicked(item);

// Натискання кнопок "Екіпірувати", "Зняти", "Видалити" у вікні інвентаря
inventoryWindow.on_Equip_clicked();
inventoryWindow.on_take_off_clicked();
inventoryWindow.on_Delete_clicked();
inventoryWindow.on_Delete_2_clicked();
```


#### Клас `MoreCharacteristics`

##### Опис
Клас `MoreCharacteristics` представляє вікно, яке відображає додаткові характеристики персонажа у грі.

##### Публічні методи

- `MoreCharacteristics(QWidget *parent = nullptr, Character maincharacter = Character())`: Конструктор класу, створює вікно для відображення додаткових характеристик персонажа.

- `~MoreCharacteristics()`: Деструктор класу, звільняє пам'ять, що була виділена для об'єкту інтерфейсу додаткових характеристик.

##### Приватні члени

- `Ui::MoreCharacteristics *ui`: Вказівник на об'єкт, що містить візуальні компоненти вікна додаткових характеристик.

- `Character character`: Об'єкт, який містить інформацію про характеристики персонажа.

##### Приклад використання

```cpp
// Створення вікна для відображення додаткових характеристик персонажа
Character mainCharacter;
MoreCharacteristics moreCharacteristicsWindow(nullptr, mainCharacter);
```

#### Клас `ShowInfoQuest`

##### Опис
Клас `ShowInfoQuest` є вікном, яке відображає інформацію про конкретний квест у грі.

##### Публічні методи

- `ShowInfoQuest(QWidget *parent = nullptr, Quest mainQuest = Quest())`: Конструктор класу, створює вікно для відображення інформації про квест.
  
- `~ShowInfoQuest()`: Деструктор класу, звільняє пам'ять, що була виділена для об'єкту інтерфейсу інформації про квест.

##### Сигнали
- `void questInfoClosed()`: Сигнал, що вказує на закриття вікна з інформацією про квест.

##### Приватні члени

- `Ui::ShowInfoQuest *ui`: Вказівник на об'єкт, що містить візуальні компоненти вікна інформації про квест.

- `Quest quest`: Об'єкт, що містить інформацію про конкретний квест.

##### Приватні слоти

- `void on_change_button_clicked()`: Слот, який викликається при натисканні кнопки зміни інформації про квест.

- `void on_Delete_Quest_clicked()`: Слот, який викликається при натисканні кнопки видалення квесту.

- `void on_Quest_complete_clicked()`: Слот, який викликається при натисканні кнопки завершення квесту.

##### Приклад використання

```cpp
// Створення вікна для відображення інформації про квест
Quest mainQuest;
ShowInfoQuest questInfoWindow(nullptr, mainQuest);
```

## Note-space

# Tag Class

## Опис
Цей файл містить клас `Tag`, який представляє тег або мітку у системі каталогізації.

## Опис класу
Клас `Tag` використовується для створення та управління тегами або мітками, що використовуються для категоризації об'єктів у системі. Він містить:

- `tagName`: приватне поле, яке зберігає назву тегу.

## Методи

### `Tag(QString new_name_tag)`
Конструктор класу, приймає назву тегу `new_name_tag` та створює новий об'єкт `Tag`.

### `getNameTag() const`
Метод, який повертає назву тегу.

## Використання

```cpp
Tag myTag("ExampleTag");
QString tagName = myTag.getNameTag();
// Результат: tagName = "ExampleTag"
```
```cpp
// Створення об'єкту тегу
Tag myTag("FirstTag");

// Отримання назви тегу
QString tagName = myTag.getNameTag();
// Результат: tagName = "FirstTag"
```


# Клас Note

## Опис
Клас `Note` відображає запис або нотатку у системі. Кожна нотатка має заголовок, текст, дату створення, список активних тегів та ідентифікатор.

## Поля класу
- `title`: назва нотатки
- `text`: текст нотатки
- `data_time`: дата і час створення нотатки
- `activeTag`: список активних тегів, які присутні у нотатці
- `idMaxValue`: статичне поле для визначення максимального ідентифікатора нотаток
- `id`: ідентифікатор нотатки

## Методи

### `Note()`
Конструктор класу, який створює об'єкт нотатки та ініціалізує час створення.

### `setTitle(QString newTitle)`
Метод для встановлення заголовку нотатки.

### `setText(QString newText)`
Метод для встановлення тексту нотатки.

### `setData_time(std::chrono::system_clock::time_point timePoint)`
Метод для встановлення часу створення нотатки.

### `addActiveTag(Tag newActiveTag)`
Метод для додавання активного тегу до нотатки.

### `deleteTag(const QString& tagName)`
Метод для видалення тегу з нотатки за назвою.

### `getActiveTag() const`
Метод, який повертає список активних тегів нотатки.

### `getTitle() const`
Метод, який повертає заголовок нотатки.

### `getText() const`
Метод, який повертає текст нотатки.

### `getDataTime() const`
Метод, який повертає дату та час створення нотатки.

### `getIdNote() const`
Метод, який повертає ідентифікатор нотатки.

## Приклад використання

```cpp
Note myNote;

myNote.setTitle("Sample Note");
myNote.setText("This is a sample text for the note.");
// ... Інші методи ...

QString noteTitle = myNote.getTitle();
std::vector<QString> noteText = myNote.getText();
std::chrono::system_clock::time_point noteDateTime = myNote.getDataTime();
int noteId = myNote.getIdNote();
// ... Інші операції з нотаткою ...
```

# Клас NoteService

Цей файл є заголовочним файлом для класу NoteService, який надає сервісні функції для роботи з нотатками.

## Опис

Клас NoteService надає функціонал для управління нотатками, включаючи додавання, видалення, пошук та зміну нотаток. Також надає доступ до списку нотаток і їх тегів.

## Залежності

Цей заголовочний файл залежить від бібліотеки `library.h` та заголовного файлу `note.h` з папки `NOTEspace/Note`, які повинні бути підключені для правильної роботи.

## Використання

### Підключення

Щоб використовувати клас NoteService, підключіть заголовочний файл `NoteService.h`:

```cpp
#include "NoteService.h"
```

### Створення об'єкта

```cpp
// Створення об'єкта NoteService
NoteService noteService;
```

### Методи класу

#### `addNote`

Додає нову нотатку до сервісу.

#### `deleteNote`

Видаляє нотатку за заголовком.

#### `getNote`

Повертає нотатку за заголовком або ID.

#### `setChangNote`

Змінює існуючу нотатку.

#### `getFirstNote`

Повертає вказівник на першу нотатку у сервісі.

#### `noteExists`

Перевіряє наявність нотатки за часом, заголовком або ID.

#### `tagsExists`

Перевіряє наявність тегів у сервісі.

#### `setNameSpaceNote`

Встановлює простір імен для нотаток.

#### `addToAllTag`

Додає тег у загальний список тегів.

#### `getAllNotes`

Повертає всі нотатки з сервісу у вигляді вектора.

#### `getNameSpaceNote`

Повертає поточний простір імен для нотаток.

#### `findIdNote`

Знаходить ID нотатки за заголовком.

#### `removeNoteFromVector`

Видаляє нотатку з вектора за її ID.

#### `returnNameNoteAndNoteID`

Повертає вектор пар з заголовками та ID нотаток.

# Клас CreateNewNoteSpaceWindow

## Опис
Клас `CreateNewNoteSpaceWindow` є вікном для створення нового простору нотаток у системі.

## Конструктори

### `CreateNewNoteSpaceWindow(QWidget *parent = nullptr)`
Конструктор класу, який створює вікно для створення нового простору нотаток. Приймає вказівник на батьківське вікно.

## Деструктор

### `~CreateNewNoteSpaceWindow()`
Деструктор класу, який звільняє пам'ять, використану для вікна створення нового простору нотаток.

## Слоти

### `on_pushButton_Add_clicked()`
Слот, який викликається при натисканні кнопки "Add" у вікні створення нового простору нотаток. Створює новий простір нотаток у головному вікні `MainWindow`.

## Приклад використання

```cpp
CreateNewNoteSpaceWindow* newNoteSpaceWindow = new CreateNewNoteSpaceWindow(parentWidget);
newNoteSpaceWindow->show();
```








