#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QColorDialog>
#include <QValidator>
QStringList strlist;
QRegExpValidator *validatorHEX = new QRegExpValidator();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    this->setFixedSize(640,360);
    this->setCentralWidget(Window);
    this->chosenColor = Qt::black;
    this->LeHEX->setText("000000");
    this->data.setHEX("000000");
    QRegExp hexcol("[0-9A-Fa-f]{6}");
    validatorHEX->setRegExp(hexcol);
    this->LeHEX->setValidator(validatorHEX);
    this->lbChosenColor->setAutoFillBackground(true);
    this->lbChosenColor->setFixedSize(100,100);
    this->PbColor->setFixedSize(120,40);
    this->LeHEX->setFixedSize(100,25);
    groupBoxesSettings();
    setDataInputLayout();
    spinBoxSettings();
    this->Variant->setFixedSize(170,25);
    strlist << "1. RGB ↔ LAB ↔ CMYK" << "2. RGB ↔ CMYK ↔ HSL" << "3. RGB ↔ XYZ ↔ LAB" << "4. RGB ↔ HSV ↔ LAB" << "5. CMYK ↔ LAB ↔ HSV" << "6. CMYK ↔ RGB ↔ HSL"
            << "7. CMYK ↔ RGB ↔ HSV" << "8. RGB ↔ XYZ ↔ HSV" << "9. HSV ↔ XYZ ↔ LAB" << "10. CMYK ↔ LAB ↔ RGB" << "11. XYZ ↔ LAB ↔ HSL" << "12. RGB ↔ XYZ ↔ HSL "
            << "13. RGB ↔ XYZ ↔ CMYK" << "14. CMYK ↔ LAB ↔ XYZ" << "15. RGB ↔ CMYK ↔ HSV" << "16. CMYK ↔ HSL ↔ XYZ" << "17. RGB ↔ HSL ↔ LAB" << "18. CMYK ↔ XYZ ↔ RGB";
    this->Variant->addItems(strlist);

    connect(this->PbColor,SIGNAL(clicked()),SLOT(ChooseColor()));
    connect(this->Variant,SIGNAL(activated(int)),SLOT(ChooseModels(int)));
    allConnect();
    ChooseModels(0);
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPalette pall;
    pall.setColor(lbChosenColor->backgroundRole(),this->chosenColor);
    lbChosenColor->setPalette(pall);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDataInputLayout()
{
    QVBoxLayout *VBox = new QVBoxLayout;
    QVBoxLayout *VBoxUp = new QVBoxLayout;
    HBoxUp->addWidget(lbChosenColor);
    VBoxUp->addWidget(this->PbColor);
    QHBoxLayout* labbox = new QHBoxLayout;
    QLabel *lbresh = new QLabel("HEX: #");
    lbresh->setFixedSize(40,25);
    labbox->addWidget(lbresh);
    labbox->addWidget(this->LeHEX);
    labbox->addWidget(Variant);
    VBoxUp->addLayout(labbox);
    HBoxUp->addLayout(VBoxUp);
    VBox->addLayout(HBoxUp);
    VBox->addLayout(HBoxDown);
    Window->setLayout(VBox);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress && obj == this->lbChosenColor)
    {
        ChooseColor();
        return true;
    }
    return false;
}

void MainWindow::ChooseColor()
{
    QColorDialog *RGB = new QColorDialog;
    this->chosenColor = RGB->getColor();
    QString s =this->chosenColor.name();
    s.remove(0,1);
    this->LeHEX->setText(s);
}
void MainWindow::ChooseModels(int i)
{

    for(int j = 0; j < this->HBoxDown->count(); ++j)
    {

         QLayoutItem* item = this->HBoxDown->itemAt(j);
         if(item)
         {
             while((item = this->HBoxDown->itemAt(0)))
             {
                  this->HBoxDown->removeItem(item);
                  this->HBoxDown->removeWidget(item->widget());
                  delete item;
             }
         }
    }
    for(int j = 0; j < 3; j++)
    {
        CurrentGBMass[j]->hide();
    }
    switch(i)
    {
    case 0:
        CurrentGBMass[0]=GroupBoxMass[0];
        CurrentGBMass[1]=GroupBoxMass[5];
        CurrentGBMass[2]=GroupBoxMass[1];
        break;
    case 1:
        CurrentGBMass[0]=GroupBoxMass[0];
        CurrentGBMass[1]=GroupBoxMass[1];
        CurrentGBMass[2]=GroupBoxMass[3];
        break;
    case 2:
        CurrentGBMass[0]=GroupBoxMass[0];
        CurrentGBMass[1]=GroupBoxMass[4];
        CurrentGBMass[2]=GroupBoxMass[5];
        break;
    case 3:
        CurrentGBMass[0]=GroupBoxMass[0];
        CurrentGBMass[1]=GroupBoxMass[2];
        CurrentGBMass[2]=GroupBoxMass[5];
        break;
    case 4:
        CurrentGBMass[0]=GroupBoxMass[1];
        CurrentGBMass[1]=GroupBoxMass[5];
        CurrentGBMass[2]=GroupBoxMass[2];
        break;
    case 5:
        CurrentGBMass[0]=GroupBoxMass[1];
        CurrentGBMass[1]=GroupBoxMass[0];
        CurrentGBMass[2]=GroupBoxMass[3];
        break;
    case 6:
        CurrentGBMass[0]=GroupBoxMass[1];
        CurrentGBMass[1]=GroupBoxMass[0];
        CurrentGBMass[2]=GroupBoxMass[2];
        break;
    case 7:
        CurrentGBMass[0]=GroupBoxMass[0];
        CurrentGBMass[1]=GroupBoxMass[4];
        CurrentGBMass[2]=GroupBoxMass[2];
        break;
    case 8:
        CurrentGBMass[0]=GroupBoxMass[2];
        CurrentGBMass[1]=GroupBoxMass[4];
        CurrentGBMass[2]=GroupBoxMass[5];
        break;
    case 9:
        CurrentGBMass[0]=GroupBoxMass[1];
        CurrentGBMass[1]=GroupBoxMass[5];
        CurrentGBMass[2]=GroupBoxMass[0];
        break;
    case 10:
        CurrentGBMass[0]=GroupBoxMass[4];
        CurrentGBMass[1]=GroupBoxMass[5];
        CurrentGBMass[2]=GroupBoxMass[3];
        break;
    case 11:
        CurrentGBMass[0]=GroupBoxMass[0];
        CurrentGBMass[1]=GroupBoxMass[4];
        CurrentGBMass[2]=GroupBoxMass[3];
        break;
    case 12:
        CurrentGBMass[0]=GroupBoxMass[0];
        CurrentGBMass[1]=GroupBoxMass[4];
        CurrentGBMass[2]=GroupBoxMass[1];
        break;
    case 13:
        CurrentGBMass[0]=GroupBoxMass[1];
        CurrentGBMass[1]=GroupBoxMass[5];
        CurrentGBMass[2]=GroupBoxMass[4];
        break;
    case 14:
        CurrentGBMass[0]=GroupBoxMass[0];
        CurrentGBMass[1]=GroupBoxMass[1];
        CurrentGBMass[2]=GroupBoxMass[2];
        break;
    case 15:
        CurrentGBMass[0]=GroupBoxMass[1];
        CurrentGBMass[1]=GroupBoxMass[3];
        CurrentGBMass[2]=GroupBoxMass[4];
        break;
    case 16:
        CurrentGBMass[0]=GroupBoxMass[0];
        CurrentGBMass[1]=GroupBoxMass[3];
        CurrentGBMass[2]=GroupBoxMass[5];
        break;
    case 17:
        CurrentGBMass[0]=GroupBoxMass[1];
        CurrentGBMass[1]=GroupBoxMass[4];
        CurrentGBMass[2]=GroupBoxMass[0];
        break;
    }
    for(int j = 0; j < 3; j++)
    {
        this->HBoxDown->addWidget(CurrentGBMass[j]);
        CurrentGBMass[j]->show();
    }
}
void MainWindow::groupBoxesSettings()
{
    this->GroupBoxMass[0]->setTitle("Color model: RGB");
    QVBoxLayout *vboxRGB = new QVBoxLayout;
    QHBoxLayout *hbox1 = new QHBoxLayout;
    QHBoxLayout *hbox2 = new QHBoxLayout;
    QHBoxLayout *hbox3 = new QHBoxLayout;
    hbox1->addWidget(new QLabel("R:"));
    hbox1->addWidget(this->RGBMass[0]);
    hbox2->addWidget(new QLabel("G:"));
    hbox2->addWidget(this->RGBMass[1]);
    hbox3->addWidget(new QLabel("B:"));
    hbox3->addWidget(this->RGBMass[2]);
    vboxRGB->addLayout(hbox1);
    vboxRGB->addLayout(hbox2);
    vboxRGB->addLayout(hbox3);
    this->GroupBoxMass[0]->setLayout(vboxRGB);

    this->GroupBoxMass[1]->setTitle("Color model: CMYK");
    QVBoxLayout *vboxCMYK = new QVBoxLayout;
    QHBoxLayout *hbox4 = new QHBoxLayout;
    QHBoxLayout *hbox5 = new QHBoxLayout;
    QHBoxLayout *hbox6 = new QHBoxLayout;
    QHBoxLayout *hbox6k = new QHBoxLayout;
    hbox4->addWidget(new QLabel("C:"));
    hbox4->addWidget(this->CMYKMass[0]);
    hbox4->addWidget(new QLabel("%"));
    hbox5->addWidget(new QLabel("M:"));
    hbox5->addWidget(this->CMYKMass[1]);
    hbox5->addWidget(new QLabel("%"));
    hbox6->addWidget(new QLabel("Y:"));
    hbox6->addWidget(this->CMYKMass[2]);
    hbox6->addWidget(new QLabel("%"));
    hbox6k->addWidget(new QLabel("K:"));
    hbox6k->addWidget(this->CMYKMass[3]);
    hbox6k->addWidget(new QLabel("%"));
    vboxCMYK->addLayout(hbox4);
    vboxCMYK->addLayout(hbox5);
    vboxCMYK->addLayout(hbox6);
    vboxCMYK->addLayout(hbox6k);
    this->GroupBoxMass[1]->setLayout(vboxCMYK);

    this->GroupBoxMass[2]->setTitle("Color model: HSV");
    QVBoxLayout *vboxHSV = new QVBoxLayout;
    QHBoxLayout *hbox7 = new QHBoxLayout;
    QHBoxLayout *hbox8 = new QHBoxLayout;
    QHBoxLayout *hbox9 = new QHBoxLayout;
    hbox7->addWidget(new QLabel("H:"));
    hbox7->addWidget(this->HSVMass[0]);
    hbox8->addWidget(new QLabel("S:"));
    hbox8->addWidget(this->HSVMass[1]);
    hbox9->addWidget(new QLabel("V:"));
    hbox9->addWidget(this->HSVMass[2]);
    vboxHSV->addLayout(hbox7);
    vboxHSV->addLayout(hbox8);
    vboxHSV->addLayout(hbox9);
    this->GroupBoxMass[2]->setLayout(vboxHSV);

    this->GroupBoxMass[3]->setTitle("Color model: HSL");
    QVBoxLayout *vboxHLS = new QVBoxLayout;
    QHBoxLayout *hbox10 = new QHBoxLayout;
    QHBoxLayout *hbox11 = new QHBoxLayout;
    QHBoxLayout *hbox12 = new QHBoxLayout;
    hbox10->addWidget(new QLabel("H:"));
    hbox10->addWidget(this->HSLMass[0]);
    hbox11->addWidget(new QLabel("S:"));
    hbox11->addWidget(this->HSLMass[2]);
    hbox11->addWidget(new QLabel("%"));
    hbox12->addWidget(new QLabel("L:"));
    hbox12->addWidget(this->HSLMass[1]);
    hbox12->addWidget(new QLabel("%"));
    vboxHLS->addLayout(hbox10);
    vboxHLS->addLayout(hbox11);
    vboxHLS->addLayout(hbox12);
    this->GroupBoxMass[3]->setLayout(vboxHLS);

    this->GroupBoxMass[4]->setTitle("Color model: XYZ");
    QVBoxLayout *vboxXYZ = new QVBoxLayout;
    QHBoxLayout *hbox13 = new QHBoxLayout;
    QHBoxLayout *hbox14 = new QHBoxLayout;
    QHBoxLayout *hbox15 = new QHBoxLayout;
    hbox13->addWidget(new QLabel("X:"));
    hbox13->addWidget(this->XYZMass[0]);
    hbox14->addWidget(new QLabel("Y:"));
    hbox14->addWidget(this->XYZMass[1]);
    hbox15->addWidget(new QLabel("Z:"));
    hbox15->addWidget(this->XYZMass[2]);
    vboxXYZ->addLayout(hbox13);
    vboxXYZ->addLayout(hbox14);
    vboxXYZ->addLayout(hbox15);
    this->GroupBoxMass[4]->setLayout(vboxXYZ);

    this->GroupBoxMass[5]->setTitle("Color model: LAB");
    QVBoxLayout *vboxLAB = new QVBoxLayout;
    QHBoxLayout *hbox16 = new QHBoxLayout;
    QHBoxLayout *hbox17 = new QHBoxLayout;
    QHBoxLayout *hbox18 = new QHBoxLayout;
    hbox16->addWidget(new QLabel("L:"));
    hbox16->addWidget(this->LABMass[0]);
    hbox17->addWidget(new QLabel("A:"));
    hbox17->addWidget(this->LABMass[1]);
    hbox18->addWidget(new QLabel("B:"));
    hbox18->addWidget(this->LABMass[2]);
    vboxLAB->addLayout(hbox16);
    vboxLAB->addLayout(hbox17);
    vboxLAB->addLayout(hbox18);
    this->GroupBoxMass[5]->setLayout(vboxLAB);

    this->CurrentGBMass[0]=GroupBoxMass[0];
    this->CurrentGBMass[1]=GroupBoxMass[1];
    this->CurrentGBMass[2]=GroupBoxMass[2];
}

void MainWindow::updateHEX()
{
    allDisconnect();
    QString hex = this->LeHEX->text();
    data.setHEX(hex);
    updateInfo();
}
void MainWindow::updateRGB()
{
    allDisconnect();
    int r = this->RGBMass[0]->value();
    int g = this->RGBMass[1]->value();
    int b = this->RGBMass[2]->value();
    data.setRGB(r, g, b);
    updateInfo();
}
void MainWindow::updateCMYK()
{
    allDisconnect();
    double c = this->CMYKMass[0]->value();
    double m = this->CMYKMass[1]->value();
    double y = this->CMYKMass[2]->value();
    double k = this->CMYKMass[3]->value();
    data.setCMYK(c, m, y, k);
    updateInfo();
}
void MainWindow::updateHSV()
{
    allDisconnect();
    double h = this->HSVMass[0]->value();
    double s = this->HSVMass[1]->value();
    double v = this->HSVMass[2]->value();
    data.setHSV(h, s, v);
    updateInfo();
}
void MainWindow::updateHSL()
{
    allDisconnect();
    double h = this->HSLMass[0]->value();
    double l = this->HSLMass[1]->value();
    double s = this->HSLMass[2]->value();
    data.setHSL(h, s, l);
    updateInfo();
}
void MainWindow::updateXYZ()
{
    allDisconnect();
    double x = this->XYZMass[0]->value();
    double y = this->XYZMass[1]->value();
    double z = this->XYZMass[2]->value();
    data.setXYZ(x, y, z);
    updateInfo();
}
void MainWindow::updateLAB()
{
    allDisconnect();
    double l = this->LABMass[0]->value();
    double a = this->LABMass[1]->value();
    double b = this->LABMass[2]->value();
    data.setLAB(l, a, b);
    updateInfo();
}
void MainWindow::updateInfo()
{
    this->LeHEX->setText(data.getHEX());
    this->RGBMass[0]->setValue(data.getR_rgb());
    this->RGBMass[1]->setValue(data.getG_rgb());
    this->RGBMass[2]->setValue(data.getB_rgb());

    this->CMYKMass[0]->setValue(data.getC_cmyk());
    this->CMYKMass[1]->setValue(data.getM_cmyk());
    this->CMYKMass[2]->setValue(data.getY_cmyk());
    this->CMYKMass[3]->setValue(data.getK_cmyk());

    this->HSVMass[0]->setValue(data.getH_hsv());
    this->HSVMass[1]->setValue(data.getS_hsv());
    this->HSVMass[2]->setValue(data.getV_hsv());

    this->HSLMass[0]->setValue(data.getH_hsl());
    this->HSLMass[1]->setValue(data.getS_hsl());
    this->HSLMass[2]->setValue(data.getL_hsl());

    this->XYZMass[0]->setValue(data.getX_xyz());
    this->XYZMass[1]->setValue(data.getY_xyz());
    this->XYZMass[2]->setValue(data.getZ_xyz());

    this->LABMass[0]->setValue(data.getL_lab());
    this->LABMass[1]->setValue(data.getA_lab());
    this->LABMass[2]->setValue(data.getB_lab());

    this->chosenColor.setNamedColor("#"+this->LeHEX->text());
    allConnect();
}

void MainWindow::spinBoxSettings()
{
    for (int i = 0; i < 3; i++)
    {
        this->RGBMass[i]->setRange(0,255);
        this->HSVMass[i]->setSingleStep(1);
        this->HSLMass[i]->setSingleStep(1);
        this->XYZMass[i]->setSingleStep(1);
        this->LABMass[i]->setSingleStep(1);
        this->HSVMass[i]->setDecimals(3);
        this->HSLMass[i]->setDecimals(3);
        this->HSLMass[i]->setDecimals(3);
        this->XYZMass[i]->setDecimals(3);
        this->LABMass[i]->setDecimals(3);
    }
    for (int i = 0; i < 4; i++)
    {
        this->CMYKMass[i]->setRange(0,100);
        this->CMYKMass[i]->setSingleStep(1);
        this->CMYKMass[i]->setDecimals(3);
    }
    this->HSVMass[0]->setRange(0,360);
    this->HSVMass[1]->setRange(0,100);
    this->HSVMass[2]->setRange(0,100);
    this->HSLMass[0]->setRange(0,360);
    this->HSLMass[1]->setRange(0,100);
    this->HSLMass[2]->setRange(0,100);
    this->XYZMass[0]->setRange(0,95.047);
    this->XYZMass[1]->setRange(0,100);
    this->XYZMass[2]->setRange(0,108.883);
    this->LABMass[0]->setRange(0,100);
    this->LABMass[1]->setRange(-128,128);
    this->LABMass[2]->setRange(-128,128);
}

void MainWindow::allConnect()
{
    for (int i = 0; i < 3; i++)
    {
        connect(this->RGBMass[i],SIGNAL(valueChanged(int)),SLOT(updateRGB()));
        connect(this->CMYKMass[i],SIGNAL(valueChanged(double)),SLOT(updateCMYK()));
        connect(this->HSLMass[i],SIGNAL(valueChanged(double)),SLOT(updateHSL()));
        connect(this->HSVMass[i],SIGNAL(valueChanged(double)),SLOT(updateHSV()));
        connect(this->XYZMass[i],SIGNAL(valueChanged(double)),SLOT(updateXYZ()));
        connect(this->LABMass[i],SIGNAL(valueChanged(double)),SLOT(updateLAB()));
    }
    connect(this->CMYKMass[3],SIGNAL(valueChanged(double)),SLOT(updateCMYK()));
    connect(this->LeHEX,SIGNAL(textChanged(QString)),SLOT(updateHEX()));
}
void MainWindow::allDisconnect()
{
    for (int i = 0; i < 3; i++)
    {
        disconnect(this->RGBMass[i],SIGNAL(valueChanged(int)),this,SLOT(updateRGB()));
        disconnect(this->CMYKMass[i],SIGNAL(valueChanged(double)),this,SLOT(updateCMYK()));
        disconnect(this->HSLMass[i],SIGNAL(valueChanged(double)),this,SLOT(updateHSL()));
        disconnect(this->HSVMass[i],SIGNAL(valueChanged(double)),this,SLOT(updateHSV()));
        disconnect(this->XYZMass[i],SIGNAL(valueChanged(double)),this,SLOT(updateXYZ()));
        disconnect(this->LABMass[i],SIGNAL(valueChanged(double)),this,SLOT(updateLAB()));
    }
    disconnect(this->CMYKMass[3],SIGNAL(valueChanged(double)),this,SLOT(updateCMYK()));
    disconnect(this->LeHEX,SIGNAL(textChanged(QString)),this,SLOT(updateHEX()));
}
