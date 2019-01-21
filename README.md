# papers-editor
# A simple, very basic text editor written using C++ and Qt5
![Screenshot of the application](https://github.com/paplio/papers-editor/blob/master/Papers/Papers%20Screenshot.png)

Papers is a very low-demand text editor, with a simple to understand user-interface, and minimal interruption to the user and his endeavors. 

Papers is written completely in C++.

The Application uses the QT Framework, which helps keep it platform-independent. This means that unlike Microsoft Word, or Sublime Text, or even Notepad, Papers does not change functionality, interface or even its general behaviour and efficiency based on the operating system being used.

#### (Please note that this is a self study project for college)

### Important snippets of the code
#### 1) Constructor to initialise Papers object of QT Type and initialise UI for app.

```
Papers::Papers(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::Papers)
{

   //this line sets up the user interface for us - initialises it
   ui->setupUi(this);
   this->setCentralWidget(ui->plainTextEdit);
   
}
```

#### 2) Set of methods written to perform specific actions if buttons are pressed.

```
void Papers::on_actionNew_triggered()

void Papers::on_actionOpen_triggered()

void Papers::on_actionSave_As_triggered()

void Papers::on_actionCopy_triggered()

(and so on)

```

####  3) Destructor to delete QWidget and close window when prompted to do so or exiting program.

```
Papers::~Papers()
{
   delete ui;   
}
```

