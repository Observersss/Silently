#include <QtTest>

// add necessary includes here
#include "../../src/NOTEspace/NoteService/noteservice.h"

class NoteSpace_test : public QObject
{
    Q_OBJECT

public:
    NoteSpace_test();
    ~NoteSpace_test();

private slots:
    void test_case1();

    void create_note_with_text();
    void create_note_with_text_and_styles();

    void test_add_2_notes_and_delete_1();
    void test_alltags_add_for_another_note();

    void get_Note_by_id();
    void get_Note_by_name();
    void get_Note_by_date();

    void set_change_note();


};

NoteSpace_test::NoteSpace_test() {}

NoteSpace_test::~NoteSpace_test() {}

void NoteSpace_test::test_case1() {}

void NoteSpace_test::create_note_with_text(){
    Note* note = NoteFactory::create();
    note->setText("Lol");
    QCOMPARE(note->getText().size(),2);
    /*  because:
     *  Note::Note(){
     *  ...
     *  text_.push_back(" ");
     *  }
    */
}
void NoteSpace_test::create_note_with_text_and_styles(){
    Note* note = NoteFactory::create();
    // I don`t have ideas why it`s not worked...
    // QVector<QString> styles;
    // note->setStyles(QVector<QString>('...'));
    // QCOMPARE(note->getStyles().size(),size_t(1));
    QVector<QString> styles;
    styles.push_back("...");
    note->setStyles(styles);
    QCOMPARE(note->getStyles().size(),size_t(1));
}

void NoteSpace_test::test_add_2_notes_and_delete_1(){
    Note* f_note = NoteFactory::create();
    f_note->setTitle("f_note");
    Note* s_note = NoteFactory::create();
    s_note->setTitle("s_note");

    NoteService result = NoteServiceFactory::create();
    result.addNote(f_note);
    result.addNote(s_note);
    result.deleteNote("f_note");

    QCOMPARE(result.getAllNotes().size(),2);
}
void NoteSpace_test::test_alltags_add_for_another_note(){
    Tag tag_t = Tag::create("...");
    NoteService noteService_t = NoteServiceFactory::create();

    Note* f_note_t = NoteFactory::create();
    f_note_t->addActiveTag(tag_t);

    noteService_t.addToAllTag(tag_t);

    Note* s_note_t = NoteFactory::create();
    s_note_t->addActiveTag(noteService_t.getAllTags()[0]);

    QCOMPARE(s_note_t->getActiveTag()[0].getNameTag(),tag_t.getNameTag());
}

void NoteSpace_test::get_Note_by_id(){
    NoteService noteService_t = NoteServiceFactory::create();
    Note* note_t = NoteFactory::create();
    note_t->setTitle("...");

    noteService_t.addNote(note_t);

    QCOMPARE(noteService_t.getNote(note_t->getIdNote())->getIdNote(),note_t->getIdNote());
}
void NoteSpace_test::get_Note_by_name(){

}
void NoteSpace_test::get_Note_by_date(){

}

void NoteSpace_test::set_change_note(){

}

QTEST_APPLESS_MAIN(NoteSpace_test)

#include "tst_notespace_test.moc"
