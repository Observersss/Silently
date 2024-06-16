# Silently
 
Проект розробляється студентами КНУ ім. Тараса Шевченка факультету комп'ютерних наук та кібернетики

### ІПС-21 Білик Вікторія Констянтинівна
### ІПС-22 Гончаренко Ілля Сергійович

## Проект: Silently
Ознайомитись з певним функціонал можна за допомогою UML діаграм що знаходяться в одноіменній папці в файловій системі проекту.

# Опис основних секцій програми
## RPG-space

#### `class Item`

##### Опис
`Item` представляє предмет у грі з певними характеристиками, рангом, назвою, описом та шляхом до зображення. Створення відбувається шляхом використанням классу `ItemFactory`. Створення іншим способом неможливе.

##### public:

- `QString getRank()const`: Повертає ранг предмету.

- `QString getnameOfitem()const`: Повертає назву предмету.

- `QString getdescriptionOfItem()const`: Повертає опис предмету.

- `std::map<QString,int>> getCharacteristics()const`: Повертає вектор з характеристиками предмету.

- `Equipment getTypeItem()const`: Повертає тип предмету(з переліку у enim Equipment).

- `QString getPathToImg() const;`: Повертає шлях до зображення предмету.

- `int getIndex()const`: Повертає унікальний індекс індекс предмету.

##### protected:

- `void setName(const QString& name)`: Задає назву предмету.

- `void setDescription(const QString& description)`: Задає опис предмету.

- `void setCharacteristics(const std::map<QString,int>>& characteristics)`: Задає характеристику предмету.

- `void setTypeOfItem(const Equipment& type)`: Задає тип предмету.

- `void setPathToImg(const QString& name)`: Задає зображення предмету.

##### Приватні члени

- `QString rank_`

- `QString nameOfItem_`

- `QString descriptionOfItem_`

- `std::map<QString,int>> characteristics_`

- `Equipment typeItem_`

- `QString pathToImg`

- `static int itemCount`

- `int index`

- `friend class DefaultItemGenerator`

#### `class ItemGeneratorStrategy`
Данний класс є прикладом паттерну Strategy який використовується для створення об'єктів `Item`. У разі створення нових типів Item(Нові атрибути і т.д). Треба реалізувати потребуючі методи в цьому класі і реалізація нового вивести в окремий класс наслідуючи данний. Непотрібні функції рекомендовано видалити.
- Приклад: `QString generateRank() = delete;`
- Всі методи классу мають специфікатор доступу `protected`
#### `protected`

- `virtual std::shared_ptr<Item> generateItem() = 0;`

- `virtual ~ItemGeneratorStrategy() = default;`
- //Basic
- `QString generateRank();`
- `std::map<QString,int>> generateCharacteristics(const QString& rank);`
- `Equipment generateTypeOfItem(const QString& name);`
- `std::pair<QString,QString> generateName();` //first - fullname, second - basic name
- Реалізовувати нові генерації за потреби

#### `class DefaultItemGenerator: public ItemGeneratorStrategy`
#####`protected:`
- `std::shared_ptr<Item> generateItem() override;`
- `friend class ItemFactory;`

#### `class itemFactory`
Данний класс використовується для більш зрозумілого інтерфейсу створення  об'єктів `Item`.
#####`protected:`
- `static std::shared_ptr<Item> create_by_default();`


#### class Inventory

##### Опис
`Inventory` представляє інвентар користувача у грі, де зберігаються об'єкти классу `Item`.

##### `public:`

- `Inventory() = default;`

- `void addItem(std::shared_ptr<Item> item);`

- `void removeItem(const std::shared_ptr<Item>& item);`

- ` bool check_if_it_contains(std::shared_ptr<Item> item);`

- `QVector<std::shared_ptr<Item>> getItems() const;`

- `int getSize() const;`

- `std::shared_ptr<Item> getItemAtIndex(size_t index) const;`
- `std::shared_ptr<Item> getItemAtName(const QString& name) const;`

##### `private:`

- ` int indexOfItem(const QString& name) const;`

- `QVector<std::shared_ptr<Item>> items_;`

####`class QuestFactory`
Паттерн фабрика для генерації завжди об'єктів `Quest` одного формату

##### `public`
- `static std::shared_ptr<Quest> create();`


#### `class Quest`

`Quest` представляє завдання в грі, яке має назву, опис, складність та дедлайн для виконання.

- `friend class QuestFactory;`

##### `public:`

- `bool checkDeadline();`

- set...

- `void setTitle(const QString& title);`

- `void setDescription(const QString& description);`

- `void setComplexity(const int& complexity);`

- `void setDeadline(const QDateTime& deadline);`

- `void switch_need_to_follow_the_deadline();`

- get...

- `int getId() const;`

- `QString getTitle()const;`

- `QString getDescription()const;`

- `int getComplexity()const;`

- `QDateTime getDeadline()const;`

- `bool get_need_to_follow_the_deadline()const;`

##### `protected:`

- `Quest();`

##### `private:`

- `static int idCount_;`

- `int id_;`

- `QString title_;`

- `QString description_;`

- `int complexity;`

- `QDateTime deadline_;`

- `bool need_to_follow_the_deadline = false;`

##### Приклад використання

```cpp
// Створення нового завдання
std::shared_ptr<Quest> mainQuest = QuestFactory::create();

// Задання назви та опису
mainQuest->setTitle("Головне завдання");
mainQuest->setDescription("Виконати серію завдань для завершення гри");
```

#### `class Character`

##### Опис
`Character` представляє персонажа в грі, що має основні характеристики, інвентар(Складається з 2 об'єктів класу `Inventory`, де один це предмети які взагалі є у користувача, а інший це предмети які активні зараз на персонажі, і напряму впливають на поточні характеристики), а також зберігає в собі активні квести(`class Quest`).

##### `public:`

- `Character()`

- `void addActiveQuest(std::shared_ptr<Quest> quest);`
- `void deleteActiveQuest(std::shared_ptr<Quest> quest);`
- `std::shared_ptr<Quest> findQuest(const QString& title);`
- `std::shared_ptr<Quest> findQuest(const int id);`

- `void addItemToInventory(std::shared_ptr<Item> item);`
- `void addItemToEquipment(std::shared_ptr<Item> item);`
- `void removeItemFromEquipment(std::shared_ptr<Item> item);`

- `void updateCharacteristicsFromInventory();`
- `void removeCharacteristicsFromUnequippedItems(const std::shared_ptr<Item> item);`

- `void incrementExperience();` - змінна experience_ збільшується рандомно в діапазоні (1,11)
- `void setHealth(int amount);`
- `void setMana(int amount);`
- `void setDamage(int amount);`
- `void setChanceOfCriticalDamade(int amount);`
- `void setCriticalDamage(int amount);`
- `void setDexterity(int amount);`
- `void setForce(int amount);`
- `void setIntelligence(int amount);`
- `void setLuck(int amount);`

- get...
- `int getHealth() const;`
- `int getMana() const;`
- `int getLevel() const;`
- `int getExperience() const;`
- `int getDamage() const;`
- `int getChanceOfCriticalDamade() const;`
- `int getCriticalDamage() const;`
- `int getDexterity() const;`
- `int getForce() const;`
- `int getIntelligence() const;`
- `int getLuck() const;`
- `Inventory* getInventory();`
- `Inventory* getEquipment();`
- `QVector<std::shared_ptr<Quest>> getActiveQuest();`

##### `protected:`

-  `void applyCharacteristicsDelta(const std::map<QString, int>& itemCharacteristics, int delta);`
За для швидкого знаходження характеристик які повинні змінитись при додаванні/видаленні певного пердмету з активного спорядження


##### `private:`

- `int health_;`
- `int mana_;`
- `int experience_;`
- `int level_;`
- `int damage_;`
- `int chanceOfCriticalDamage_;`
- `int criticalDamage_;`
- `int dexterity_;`
- `int force_;`
- `int intelligence_;`
- `int luck_;`

- `Inventory inventory_;` - Предмети які просто зберігаються у персонажа
- `Inventory equipment_;` - Екіпійовані предмети
- `QVector<std::shared_ptr<Quest>>activeQuests_;`

##### Приклад використання

```cpp
// Створення нового персонажа
Character mainCharacter;

// Додавання квесту та предмету до інвентаря персонажа
std::shared_ptr<Quest> newQuest = QuestFactory::create();
mainCharacter.addActiveQuest(newQuest);

std::shared_ptr<Item> newItem = ItemFactory::create_by_default();
mainCharacter.addItemToInventory(newItem);

// Збільшення опиту та оновлення рівня персонажа
mainCharacter.incrementExperience();
```

### `class MainWindow`

## Опис
Клас `MainWindow` є головним вікном програми. Цей клас відповідає за управління графічним інтерфейсом користувача та інтеракції з різними компонентами програми, такими як простір нотаток, RPG-система та інші елементи.

##### `public:`

- `MainWindow(QWidget *parent = nullptr);`
- `void addActiveQuest(std::shared_ptr<Quest> quest);`

- `void updateInfoOnCharacter();`

- `void updateInfoOnQuest();`

- `void handleQuestInfoClosed();`

- `void deleteQuest(std::shared_ptr<Quest> quest);`

- `void questComplete();`

- `void addTag(QString name,bool needAddToAllTags = true);`

- `void updateInfoTag();`

- `NoteService* returnNoteServicePtr();`
- `NoteService* returnNoteServicePtr(QString text);`

- `void AddNoteSpace(QString nameNoteService);`
- `void deleteNoteSpace(QString nameNoteService);`

- `void saveInfoNote(QListWidgetItem *previous);`
- `void uploadInfoNote(QListWidgetItem *current);`

- `void update_listWidget_Quests();`

- `~MainWindow();`

##### `private slots:`

- `void checkQuestDeadlinePassed();`

- `void on_delete_Note_Service_clicked();`

- `void on_listTag_itemDoubleClicked(QListWidgetItem *item);`

- `void createNote();`

- `void on_listWidget_Quests_itemDoubleClicked(QListWidgetItem *item);`


##### `private:`

- `Ui::MainWindow *ui;`
- `Character character;`
- `std::vector<NoteService> noteSpaces;`
- `int bufferNoteId;`
- `QString bufferNoteSpace;`
- `static int noteCounter;`
- `bool showUpdateCharacteristics = false;`

- `void connect_Signals_and_Slots();`
- `void change_space();`

### `class CustomLineEdit`

#### Опис
`CustomLineEdit` є спеціалізованим віджетом, який поєднує в собі `QLineEdit` для введення тексту та додаткові можливості для форматування тексту та взаємодії з користувачем через контекстне меню.

#### `public:`

- `explicit CustomLineEdit(QWidget *parent = nullptr);`
  Конструктор класу, ініціалізує віджет `QLineEdit` та контекстне меню.

- `void setText(const QString& text);`
  Встановлює текст у поле введення.

- `void setStyleSheet(const QString &styleSheet);`
  Встановлює стилізацію для віджету за допомогою CSS.

- `QString text() const;`
  Повертає поточний текст у полі введення.

- `QString style() const;`
  Повертає поточну CSS стилізацію віджету.

- `QLineEdit* getlineEdit() const;`
  Повертає внутрішній об'єкт `QLineEdit`.

- `~CustomLineEdit();`
  Деструктор, відповідає за звільнення ресурсів, використовуваних віджетом.

#### Сигнали:

- `void deleteRequested();`
  Сигнал, що відправляється при запиті на видалення віджету.

- `void textFormattingRequested(QFont::Weight weight, bool italic, bool uppercase);`
  Сигнал, що відправляється при запиті на форматування тексту з вказанням ваги шрифту, нахилу та верхнього регістру.

- `void editingFinished();`
  Сигнал, що відправляється при завершенні редагування тексту.

#### `private slots:`

- `void showMenu();`
  Слот, що відображає контекстне меню для вибору опцій.

- `void handleMenuAction();`
  Обробник події вибору дії з контекстного меню.

- `void handleTextFormattingRequest(QFont::Weight weight, bool italic, bool uppercase);`
  Обробник запиту на форматування тексту.

- `void handleDeleteCustomLineEdit();`
  Обробник запиту на видалення віджету.

- `void changeTextColor(const QColor &color);`
  Змінює колір тексту у полі введення.

- `void changeBackgroundColor(const QColor &color);`
  Змінює фоновий колір у полі введення.

- `bool eventFilter(QObject *watched, QEvent *event);`
  Обробник подій для відстеження подій у віджеті.

- `void manageActiveButton(bool isActive);`
  Управляє активністю кнопки.

#### Захищені методи:

- `void focusInEvent(QFocusEvent *event) override;`
  Обробник події входу в фокус віджета.

- `void focusOutEvent(QFocusEvent *event) override;`
  Обробник події виходу з фокуса віджета.

#### Приватні поля:

- `QLineEdit *lineEdit;`
  Об'єкт `QLineEdit`, що використовується для введення тексту.

- `QPushButton *menuButton;`
  Кнопка для відкриття контекстного меню.

- `QMenu *popupMenu;`
  Контекстне меню з опціями для віджета.

#### Приватні методи:

- `void connectSignalsAndSlots();`
  Підключає сигнали до слотів віджета.

- `void createPopupMenu();`
  Створює контекстне меню з необхідними опціями.

---

### `class CustomLineEditBuilder`

#### Опис
`CustomLineEditBuilder` є білдером для класу `CustomLineEdit`, який дозволяє побудувати віджет з попередньо заданими параметрами.

#### `public:`

- `CustomLineEditBuilder(QWidget* parent = nullptr);`
  Конструктор білдера, приймає батьківський віджет для створення віджета.

- `CustomLineEditBuilder& withText(const QString& text);`
  Встановлює текст для поля введення.

- `CustomLineEditBuilder& withStyles(const QString& style);`
  Встановлює CSS стилізацію для віджета.

- `CustomLineEdit* build();`
  Збирає і повертає готовий об'єкт `CustomLineEdit` з заданими параметрами.

---

### `class CustomLineEditFactory`

#### Опис
`CustomLineEditFactory` є фабрикою, яка створює різні варіанти об'єктів `CustomLineEdit` за допомогою білдера `CustomLineEditBuilder`.

#### `public:`

- `static CustomLineEdit* create(QWidget* parent = nullptr);`
  Створює стандартний варіант об'єкта `CustomLineEdit`.

- `static CustomLineEdit* create_with_text(const QString& text = "", QWidget* parent = nullptr);`
  Створює об'єкт `CustomLineEdit` з встановленим текстом.

- `static CustomLineEdit* create_with_style(const QString& style = "", QWidget* parent = nullptr);`
  Створює об'єкт `CustomLineEdit` з встановленою CSS стилізацією.

- `static CustomLineEdit* create_with_text_and_style(const QString& text = "", const QString& style = "", QWidget* parent = nullptr);`
  Створює об'єкт `CustomLineEdit` з встановленим текстом та CSS стилізацією.

#### Приклад використання:

```cpp
// Створення віджета CustomLineEdit з певним текстом та стилізацією
CustomLineEdit* lineEdit = CustomLineEditFactory::create_with_text_and_style("Initial text", LINE_EDIT_STYLE, parentWidget);

// Встановлення обробників подій для віджета
connect(lineEdit, &CustomLineEdit::deleteRequested, deleteHandler);
connect(lineEdit, &CustomLineEdit::textFormattingRequested, textFormatHandler);
connect(lineEdit, &CustomLineEdit::editingFinished, editFinishHandler);

// Відображення віджета
lineEdit->show();
```

### `class CustomLineEditManager`

#### Опис
`CustomLineEditManager` є класом, який управляє створенням, управлінням і отриманням даних з об'єктів `CustomLineEdit`. Він забезпечує можливість створення, встановлення тексту і стилізації, отримання даних та інші функції для маніпулювання групою віджетів `CustomLineEdit`.

#### `public:`

- `static CustomLineEditManager *getInstance(QObject *parent = nullptr);`
  Статичний метод для отримання єдиного екземпляру класу `CustomLineEditManager`.

- `void setLayoutAndScroolArea(QLayout* layout, QScrollArea* scroolArea);`
  Встановлює Layout (`QLayout`) та ScroolArea (`QScrollArea`) для розміщення `CustomLineEdit`.

- `void create_CustomLineEdit();`
  Створює новий віджет `CustomLineEdit` та додає його до відповідного Layout.

- `void clearLayout();`
  Очищує Layout від усіх елементів.

- `void setTextForCustomLineEdit(QVector<QString> text);`
  Встановлює текст для всіх `CustomLineEdit` з вектора `text`.

- `void setStyleForCustomLineEdit(QVector<QString> styles);`
  Встановлює стилізацію для всіх `CustomLineEdit` з вектора `styles`.

- `void setTextWithStylesForCustomLineEdit(std::pair<QVector<QString>, QVector<QString>> vectors);`
  Встановлює текст та стилізацію для `CustomLineEdit` з векторів тексту і стилів.

- `QVector<QString> getTextFromLineEdits() const;`
  Отримує текст з усіх `CustomLineEdit`.

- `QVector<QString> getStylesFromLineEdits() const;`
  Отримує стилізацію з усіх `CustomLineEdit`.

- `std::pair<QVector<QString>, QVector<QString>> getTextWithStyles();`
  Отримує пару векторів тексту і стилів з усіх `CustomLineEdit`.

#### `private:`

- `explicit CustomLineEditManager(QObject *parent = nullptr);`
  Приватний конструктор для ініціалізації класу. Забороняє пряме створення екземплярів за межами класу.

- `static CustomLineEditManager *instance;`
  Єдиний екземпляр класу `CustomLineEditManager`.

- `QLayout* layout;`
  Layout для розміщення `CustomLineEdit`.

- `QScrollArea* scroolArea;`
  Область прокрутки, до якої додаються `CustomLineEdit`.

- `QVector<CustomLineEdit*> lineEdits;`
  Вектор, що містить усі створені екземпляри `CustomLineEdit`.

#### Приватні методи:

- `void create_CustomLineEdit_with_Text(QString text);`
  Створює новий `CustomLineEdit` з вказаним текстом і додає його до Layout.

- `void create_CustomLineEdit_with_Style(QString style);`
  Створює новий `CustomLineEdit` з вказаною стилізацією і додає його до Layout.

- `void create_CustomLineEdit_with_Text_and_Style(QString text, QString style);`
  Створює новий `CustomLineEdit` з вказаним текстом і стилізацією, додає його до Layout.

- `void delete_CustomLineEdit(CustomLineEdit* currentLineEdit);`
  Видаляє вказаний екземпляр `CustomLineEdit`.

- `void focusNextCustomLineEdit(CustomLineEdit *currentLineEdit);`
  Переходить до наступного `CustomLineEdit` після поточного.

- `void focusPrevCustomLineEdit(CustomLineEdit *currentLineEdit);`
  Переходить до попереднього `CustomLineEdit` перед поточним.

#### Примітка:
Клас `CustomLineEditManager` служить для керування групою віджетів `CustomLineEdit`, дозволяючи динамічно створювати, управляти їх вмістом та стилізацією, а також отримувати дані з цих віджетів.
#### `class addQuest_DialogWindow`

##### Опис
`addQuest_DialogWindow` відображає вікно для додавання нового квесту у гру. Воно дозволяє встановлювати назву, опис, складність та дедлайн для нового завдання.

Методи : 
        `on_pushButton_show_deadline_clicked` - відображає поля для вводу дедлайну( с початку вони приховані для користувача)
        `on_pushButton_add_quest_clicked` - створює покажчик на `MainWindow` за допомогою `dynamic_cast` і викликає методи(`addActiveQuest` , `updateInfoOnQuest`)

##### `public:`

- `explicit addQuest_DialogWindow(QWidget *parent = nullptr);`
- `~addQuest_DialogWindow();`

##### `private slots:`

- `void on_pushButton_show_deadline_clicked();`
- `void on_pushButton_add_quest_clicked`

##### `private:`

- `Ui::addQuest_DialogWindow *ui;`
- `std::shared_ptr<Quest> quest_;`


#### `class Inventory_DialogWindow`

##### Опис
 `Inventory_DialogWindow` відображає вікно інвентаря персонажа. Він дозволяє користувачеві переглядати, екіпірувати, знімати екіпірування та видаляти предмети з інвентаря.

##### `public:`

- `explicit Inventory_DialogWindow(QWidget *parent = nullptr, Character *playerCharacter = nullptr);`

- `void showItemDetails(std::shared_ptr<Item> selectedItem);`

- `bool checkTypeCount(Equipment equipment);`
- `bool EquipmentAddToEquipment(Equipment equipment);`
- `bool EquipmentRemoveFromEquipment(Equipment equipment);`

 - `~Inventory_DialogWindow();`

##### `private slots:`

- `void on_listWidget_Inventory_Items_itemClicked(QListWidgetItem *item);`

- `void on_listWidget_Equip_Items_itemClicked(QListWidgetItem *item);`

- `void on_pushButton_Equip_current_item_clicked();`

- `void on_pushButton_take_off_current_item_clicked();`

- `void on_pushButton_delete_current_Item_clicked();`

##### `private:`

- `Ui::Inventory_DialogWindow *ui;`
- `Character *character;`
- `std::map<Equipment,int> typeCount;`

- `void addItemToListWidget(const QString &itemName, QListWidget *listWidget);`
- `void removeItemFromListWidget(QListWidget *listWidget, int selectedIndex);`
- `Item* findItemByName(const QString &itemName, const QVector<Item*>& items);`
- `void updateCharacterFromInventory();`
- `void removeCharacteristicsFromItems(const std::vector<Item> &items);`


##### Приклад використання

```cpp
// Створення вікна інвентаря для конкретного персонажа
Character playerCharacter;
InventoryWindow inventoryWindow(nullptr, &playerCharacter);

// Натискання на предмет у списку інвентаря для відображення його характеристик
inventoryWindow.on_listWidget_Inventory_Items_itemClicked(item);

// Натискання кнопок "Екіпірувати", "Зняти", "Видалити" у вікні інвентаря
inventoryWindow.on_pushButton_Equip_current_item_clicked();

inventoryWindow.on_listWidget_Equip_Items_itemClicked();
inventoryWindow.on_pushButton_take_off_current_item_clicked(); 

inventoryWindow.on_listWidget_Inventory_Items_itemClicked(item);
inventoryWindow.on_pushButton_delete_current_Item_clicked();
```


#### `class MoreCharacteristics_DialogWindow`

##### Опис
Клас `MoreCharacteristics_DialogWindow` представляє вікно, яке відображає додаткові характеристики персонажа у грі.

##### `public:`

- `explicit MoreCharacteristics_DialogWindow(QWidget *parent = nullptr,Character* maincharacter=nullptr,bool show=false);`
- `~MoreCharacteristics_DialogWindow();`

- `void updateInfo();`
- `void changeValueEvent();`

##### `public slots:`

- `void on_spinBox_valueChanged(int arg1);`
     
##### `private slots:`

- `void on_pushButton_clicked();`

##### `private:`

- `Ui::MoreCharacteristics_DialogWindow *ui;`
- `Character* character;`
- `int countPoint = 12;`
- `std::map<QSpinBox*,int> boxes;`

##### Приклад використання


#### ` class ShowInfoQuest_DialogWindow`

##### Опис
Клас `ShowInfoQuest` є вікном, яке відображає інформацію про конкретний квест у грі.

##### `public:`

- `explicit ShowInfoQuest_DialogWindow(QWidget *parent = nullptr,std::shared_ptr<Quest> quest = nullptr);`
- `~ShowInfoQuest_DialogWindow();`
     
##### `private slots:`

- `void on_pushButton_save_changes_clicked();`

- `void on_pushButton_delete_Quest_clicked();`

- `void on_pushButton_complete_Quest_clicked();`

##### `private:`

- `Ui::ShowInfoQuest_DialogWindow *ui;`
- `std::shared_ptr<Quest> quest_;`

- `MainWindow* getMainWindow();`


## Note-space

#### `class Tag`

##### Опис
`Tag` представляє тег, який використовується для позначення або категоризації різних об'єктів у системі. Клас надає можливість створення тега та отримання його назви.

##### `private:`

- `QString tagName_;`
  Зберігає назву тега.

- `Tag(const QString& new_name_tag);`
  Приватний конструктор для створення тега з вказаною назвою.

##### `public:`

- `static Tag create(const QString& new_name_tag);`
  Статичний метод для створення нового тега з вказаною назвою.

- `QString getNameTag() const;`
  Повертає назву тега.

##### Приклад використання

```cpp
// Створення нового тега
Tag newTag = Tag::create("Adventure");

// Отримання назви тега
QString tagName = newTag.getNameTag();
```
#### `class AddTag_DialogWindow`

##### Опис
`AddTag_DialogWindow` представляє діалогове вікно для додавання нового тегу. Вікно має можливість вибору існуючих тегів або створення нового. Забезпечує інтерфейс для введення нових даних користувачем і містить відповідні слоти для обробки подій.

##### `public:`

- `explicit AddTag_DialogWindow(QWidget *parent = nullptr, const QVector<Tag>* tags = nullptr);`
  Конструктор, що ініціалізує діалогове вікно для додавання тегу. Приймає опціональний батьківський віджет та вказівник на вектор існуючих тегів `tags`.

- `~AddTag_DialogWindow();`
  Деструктор, що викликається при знищенні об'єкта діалогового вікна.

##### `private slots:`

- `void on_pushButton_clicked();`
  Слот, що викликається при натисканні кнопки "Готово". Використовується для обробки події завершення додавання тегу.

- `void on_button_option_clicked();`
  Слот, що викликається при натисканні кнопки "Опції". Використовується для обробки події показу або приховування фрейму опцій вибору тегу.

##### `private:`

- `Ui::AddTag_DialogWindow *ui;`
  Вказівник на інтерфейс користувача, що створюється за допомогою класу `Ui::AddTag_DialogWindow`.

- `const QVector<Tag>* _tags;`
  Вказівник на вектор існуючих тегів.

- `bool select_tag_frame_hide = false;`
  Прапорець для відображення або приховування фрейму вибору існуючих тегів.

- `bool create_tag_frame_hide = false;`
  Прапорець для відображення або приховування фрейму створення нового тегу.

##### Приклад використання

```cpp
// Створення діалогового вікна для додавання тегу
AddTag_DialogWindow* dialog = new AddTag_DialogWindow(parentWidget, &existingTags);

// Відображення діалогового вікна
dialog->exec();
```

#### `class Note`

##### Опис
`Note` представляє нотатку, яка містить заголовок, текст, стилі, час створення та активні теги. Клас забезпечує методи для налаштування та отримання цих характеристик, а також для порівняння нотаток за заголовком, ідентифікатором та часом створення.

##### `public:`

- `Note();`
  Базовий конструктор, який ініціалізує час створення нотатки.

- `void setTitle(const QString& newTitle);`
  Задає заголовок нотатки.

- `void setText(const QString& newText);`
  Задає текст нотатки.

- `void setText(const QVector<QString>& newText);`
  Задає текст нотатки з вектором рядків.

- `void setStyles(const QVector<QString>& _styles);`
  Задає стилі тексту.

- `void setTextWithStyles(const std::pair<QVector<QString>, QVector<QString>>& vectors);`
  Задає текст та стилі у вигляді пари векторів.

- `void setData_time(const QDateTime& timePoint);`
  Задає час створення нотатки.

- `void addActiveTag(const QString& newActiveTag);`
  Додає активний тег до нотатки.

- `void setNewActiveTags(const QVector<QString>& newActiveTags);`
  Задає новий набір активних тегів.

- `void deleteTag(const QString& tagName);`
  Видаляє тег з активних тегів нотатки.

- `QVector<Tag> getActiveTag() const;`
  Повертає вектор активних тегів.

- `QString getTitle() const;`
  Повертає заголовок нотатки.

- `QVector<QString> getText() const;`
  Повертає текст нотатки.

- `QVector<QString> getStyles() const;`
  Повертає стилі тексту нотатки.

- `std::pair<QVector<QString>, QVector<QString>> getTextWithStyles() const;`
  Повертає текст і стилі у вигляді пари векторів.

- `QDateTime getDataTime() const;`
  Повертає час створення нотатки.

- `int getIdNote() const;`
  Повертає ідентифікатор нотатки.

- `bool operator==(const QString& otherTitle) const;`
  Порівнює заголовок нотатки з іншим заголовком.

- `bool operator==(const int& otherId) const;`
  Порівнює ідентифікатор нотатки з іншим ідентифікатором.

- `bool operator==(const QDateTime& otherDateOfCreation) const;`
  Порівнює час створення нотатки з іншим часом.

- `Note& operator=(const Note& other);`
  Оператор присвоєння для нотатки.

##### `private:`

- `QString title_;`
  Заголовок нотатки.

- `QVector<QString> text_;`
  Текст нотатки.

- `QVector<QString> styles_;`
  Стилі тексту нотатки.

- `QDateTime dateOfCreation_;`
  Час створення нотатки.

- `QVector<Tag> activeTag_;`
  Активні теги нотатки.

- `static int idMaxValue_;`
  Максимальне значення ідентифікатора.

- `int id_;`
  Ідентифікатор нотатки.

##### `class NoteFactory`

##### Опис
`NoteFactory` забезпечує створення нових об'єктів `Note`.

##### `public:`

- `static Note* create();`
  Створює новий об'єкт `Note`.

##### Приклад використання

```cpp
// Створення нової нотатки
Note* newNote = NoteFactory::create();

// Задання заголовку нотатки
newNote->setTitle("Meeting Notes");

// Задання тексту нотатки
newNote->setText("Discuss the new project timeline.");

// Задання стилів тексту
QVector<QString> styles = {"bold", "italic"};
newNote->setStyles(styles);

// Додавання активного тега
newNote->addActiveTag("Work");

// Отримання заголовку нотатки
QString title = newNote->getTitle();

// Порівняння заголовків нотаток
if (*newNote == "Meeting Notes") {
    // Дії, якщо заголовок збігається
}

// Видалення тега
newNote->deleteTag("Work");

// Отримання всіх активних тегів
QVector<Tag> tags = newNote->getActiveTag();
```

#### `class NoteService`

##### Опис
`NoteService` забезпечує управління нотатками, включаючи їх створення, видалення, пошук і зміну. Клас також дозволяє працювати з тегами та простором імен для нотаток.

##### `public:`

- `void setNameSpaceNote(const QString& name);`
  Встановлює простір імен для нотаток.

- `void addNote(Note* note);`
  Додає нову нотатку.

- `void deleteNote(const QString& noteTitle);`
  Видаляє нотатку за її заголовком.

- `void addToAllTag(const QString& tagName);`
  Додає новий тег до всіх тегів.

- `void setChangeNote(Note* note);`
  Змінює інформацію нотатки.

- `void setChangeNote(Note* note, const QString& oldName);`
  Змінює інформацію нотатки, замінюючи старий заголовок.

- `int findIdNote(const QString& nameNote);`
  Знаходить ідентифікатор нотатки за її заголовком.

- `Note* getFirstNote() const;`
  Повертає першу нотатку.

- `Note* getNote(const int& id);`
  Повертає нотатку за ідентифікатором.

- `Note* getNote(const QString& name);`
  Повертає нотатку за заголовком.

- `Note* getNote(const QDateTime& dateOfCreation);`
  Повертає нотатку за часом створення.

- `template <typename T> Note* getNote(const T& arg);`
  Повертає нотатку за будь-яким заданим параметром типу `T`.

- `QVector<Note*> getAllNotes() const;`
  Повертає всі нотатки.

- `QVector<Tag> getAllTags() const;`
  Повертає всі теги.

- `QString getNameSpaceNote() const;`
  Повертає простір імен для нотаток.

- `std::unordered_map<QString, int> returnNameNoteAndNoteID() const;`
  Повертає мапу заголовків нотаток і їх ідентифікаторів.

##### `protected:`

- `NoteService();`
  Конструктор за замовчуванням, створює `NoteService`.

- `NoteService(const QString& nameSpace);`
  Конструктор, що створює `NoteService` з заданим простором імен.

- `template<typename T> Note* findNote(const T& value);`
  Знаходить нотатку за будь-яким заданим параметром типу `T`.

- `void addNewElement_to_NameNoteAndNoteID(const QString& title, const int& id);`
  Додає новий елемент у мапу заголовків нотаток і їх ідентифікаторів.

- `void changeInfo_into_NameNoteInVector(const QString& newName, const int& oldID);`
  Змінює інформацію про нотатку у векторі заголовків.

- `void removeElement_from_nameNoteAndNoteID(const int& id);`
  Видаляє елемент з мапи заголовків нотаток і їх ідентифікаторів.

##### `private:`

- `QString nameSpaceNote_;`
  Простір імен для нотаток.

- `static QVector<Tag> allTag_;`
  Всі теги.

- `QVector<Note*> notes_;`
  Всі нотатки.

- `std::unordered_map<QString, int> nameNoteAndNoteID_;`
  Мапа заголовків нотаток і їх ідентифікаторів.

- `static const QString BASIC_NAME_NOTE = "Your first Note";`
  Базовий заголовок нотатки.

##### `class NoteServiceFactory`

##### Опис
`NoteServiceFactory` забезпечує створення нових об'єктів `NoteService`.

##### `public:`

- `static NoteService create();`
  Створює новий об'єкт `NoteService`.

- `static NoteService create_with_text(const QString& name);`
  Створює новий об'єкт `NoteService` з заданим простором імен.

##### Приклад використання

```cpp
// Створення нового сервісу нотаток
NoteService noteService = NoteServiceFactory::create();

// Створення нового сервісу нотаток з заданим простором імен
NoteService customNoteService = NoteServiceFactory::create_with_text("Personal");

// Додавання нової нотатки
Note* newNote = NoteFactory::create();
newNote->setTitle("Meeting Notes");
noteService.addNote(newNote);

// Видалення нотатки за заголовком
noteService.deleteNote("Meeting Notes");

// Пошук нотатки за ідентифікатором
Note* foundNote = noteService.getNote(1);

// Додавання нового тега
noteService.addToAllTag("Important");

// Отримання всіх нотаток
QVector<Note*> allNotes = noteService.getAllNotes();

// Отримання всіх тегів
QVector<Tag> allTags = noteService.getAllTags();
```

#### `class AddNoteSpace_DialogWindow`

##### Опис
`AddNoteSpace_DialogWindow` представляє діалогове вікно для додавання нового простору нотаток. Це вікно забезпечує інтерфейс для введення нових даних користувачем і містить відповідні слоти для обробки подій.

##### `public:`

- `explicit AddNoteSpace_DialogWindow(QWidget *parent = nullptr);`
  Конструктор, що ініціалізує діалогове вікно. Опціонально приймає батьківський віджет.

- `~AddNoteSpace_DialogWindow();`
  Деструктор, що викликається при знищенні об'єкта діалогового вікна.

##### `private slots:`

- `void on_pushButton_Add_clicked();`
  Слот, що викликається при натисканні кнопки "Додати". Використовується для обробки події додавання нового простору нотаток.

##### `private:`

- `Ui::AddNoteSpace_DialogWindow *ui;`
  Вказівник на інтерфейс користувача, що створюється за допомогою класу `Ui::AddNoteSpace_DialogWindow`.

##### Приклад використання

```cpp
// Створення діалогового вікна для додавання нового простору нотаток
AddNoteSpace_DialogWindow* dialog = new AddNoteSpace_DialogWindow(parentWidget);

// Відображення діалогового вікна
dialog->exec();
```
