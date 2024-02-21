//#include <QtTest>

//// add necessary includes here

//class NoteService_test : public QObject
//{
//    Q_OBJECT

//public:
//    NoteService_test();
//    ~NoteService_test();

//private slots:
//    void test_case1();
//};

//NoteService_test::NoteService_test() {}

//NoteService_test::~NoteService_test() {}

//void NoteService_test::test_case1() {}

//QTEST_APPLESS_MAIN(NoteService_test)

//#include "tst_noteservice_test.moc"

#include <QCoreApplication>
#include <QtTest>

// Add necessary includes here
#include "../../src/RPGspace/NoteService/noteservice.h"

class NoteServiceTest : public QObject
{
    Q_OBJECT

public:
    NoteServiceTest(); // Constructor declaration
    ~NoteServiceTest(); // Destructor declaration

private slots:
    // Test cases declarations
    void testAddNote();
    void testDeleteNote();
    void testGetNoteByTitle();
    void testGetNoteById();
    void testSetChangeNoteByDateTime();
    void testSetChangeNoteByTitle();
    void testNoteExistsByDateTime();
    void testNoteExistsByTitle();
    void testNoteExistsById();
    void testTagsExists();
    void testSetNameSpaceNote();
    void testGetAllNotes();
    void testGetNameSpaceNote();
    void testGetNotePtr();
    void testFindIdNote();
    void testChangeNameNoteInVector();
    void testRemoveNoteFromVector();
    void testAddNewElementToNameNoteAndNoteID();
    void testReturnNameNoteAndNoteID();
};

NoteServiceTest::NoteServiceTest() {} // Constructor definition

NoteServiceTest::~NoteServiceTest() {} // Destructor definition

// Test case to verify adding a note
void NoteServiceTest::testAddNote() {
    NoteService noteService;
    Note note;
    noteService.addNote(note);
    QCOMPARE(noteService.getAllNotes().size(), 1);
}

// Test case to verify deleting a note
void NoteServiceTest::testDeleteNote() {
    NoteService noteService;
    Note note;
    noteService.addNote(note);
    noteService.deleteNote(note.getTitle());
    QCOMPARE(noteService.getAllNotes().size(), 0);
}

// Test case to verify getting a note by its title
void NoteServiceTest::testGetNoteByTitle() {
    NoteService noteService;
    Note note;
    note.setTitle("Test Note");
    noteService.addNote(note);
    QCOMPARE(noteService.getNoteByTitle("Test Note").getTitle(), "Test Note");
}

// Test case to verify getting a note by its ID
void NoteServiceTest::testGetNoteById() {
    NoteService noteService;
    Note note;
    note.setIdNote(1);
    noteService.addNote(note);
    QCOMPARE(noteService.getNoteById(1).getIdNote(), 1);
}

// Test case to verify setting and changing a note by its date time
void NoteServiceTest::testSetChangeNoteByDateTime() {
    NoteService noteService;
    Note note;
    noteService.addNote(note);
    Note newNote;
    noteService.setChangeNoteByDateTime(newNote);
    QCOMPARE(noteService.getFirstNote()->getDataTime(), newNote.getDataTime());
}

// Test case to verify setting and changing a note by its title
void NoteServiceTest::testSetChangeNoteByTitle() {
    NoteService noteService;
    Note note;
    noteService.addNote(note);
    Note newNote;
    noteService.setChangeNoteByTitle(newNote, "Your first note");
    QCOMPARE(noteService.getNoteByTitle("Your first note").getTitle(), newNote.getTitle());
}

// Test case to verify if a note exists by its date time
void NoteServiceTest::testNoteExistsByDateTime() {
    NoteService noteService;
    Note note;
    noteService.addNote(note);
    QVERIFY(noteService.noteExists(note.getDataTime()));
}

// Test case to verify if a note exists by its title
void NoteServiceTest::testNoteExistsByTitle() {
    NoteService noteService;
    Note note;
    note.setTitle("Test Note");
    noteService.addNote(note);
    QVERIFY(noteService.noteExists("Test Note"));
}

// Test case to verify if a note exists by its ID
void NoteServiceTest::testNoteExistsById() {
    NoteService noteService;
    Note note;
    note.setIdNote(1);
    noteService.addNote(note);
    QVERIFY(noteService.noteExists(1));
}

// Test case to verify if tags exist
void NoteServiceTest::testTagsExists() {
    NoteService noteService;
    std::vector<QString> tagNames = {"tag1", "tag2"};
    noteService.tagsExists(tagNames);
    QCOMPARE(noteService.getAllTags().size(), 2);
}



QTEST_MAIN(NoteServiceTest) // Define the test runner

#include "tst_noteservicetest.moc" // Include the generated moc file
