#include "dialog.h"
#include <QFrame>
#include <QSlider>
#include <QTimer>
#include "circularprogressbar.h"
#include <QLayout>

Dialog::Dialog(QMainWindow *parent) : QMainWindow(parent)
{

    resize(500,500);

    val = 0;

//        setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QFrame *frame = new QFrame;
    layout = new QVBoxLayout;


    frame->setStyleSheet("background-color : transparent");

    progressbar = new CircularProgressBar;
    progressbar->setValue(50);
    progressbar->setWidth(200);
    progressbar->setHeight(200);
    progressbar->setMargin(15);
    progressbar->setMax_value(100);
    progressbar->setText_color(Qt::white);
    progressbar->setProgress_color("#4dae7e");
    progressbar->setCircle_color("#3a3d67");
    progressbar->setEnable_shadow(false);
    progressbar->setProgress_width(10);
    progressbar->setProgress_rounded_cap(true);

    progressbar->add_shadow(true);


    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0,100);
    slider->setStyleSheet("color: #06df70");
    slider->setMaximumWidth(progressbar->width());

//    progressbar->setText("<p align='center' style='color:green'>This is demo content.</p>");
    progressbar->setText(QString("<div align='center' \
                         style='\
                           display: flex;\
                           justify-content: center;\
                           flex-flow: nowrap column;\
                           color: #fff;\
                         '\
                       >\
                         <div align='center'>\
                           <strong style='text-transform: uppercase; font-size: x-small'>cpu</strong>\
                           <span\
                             style='text-transform: uppercase; font-size: x-small; color: lightgray'\
                           >\
                             usage</span\
                           >\
                         </div>\
                         <div align='center'\
                           style='\
                             display: flex;\
                             align-items: flex-start;\
                             font-size: 50px;\
                             color: #4daf7e; \
                             '\
                         >\
                           <span>%1</span>\
                           <span align='center' style='font-size: 30px;'>%</span>\
                         </div>\
                       \
                         <div align='center' style='font-size: x-small;'>\
                           <span align='center' style='color: grey; text-transform: uppercase;'>temp</span>\
                           <span align='center' style='color: lightgrey;'> 60</span>\
                         </div>\
                       </div>").arg(slider->value()));

    setMinimumSize(progressbar->width(),progressbar->height());



    layout->addWidget(progressbar,Qt::AlignCenter);
    layout->addWidget(slider,Qt::AlignCenter);
    layout->setAlignment(Qt::AlignCenter);

    connect(slider,&QSlider::valueChanged,progressbar,&CircularProgressBar::_onValueChange);
    connect(this,&Dialog::textChanged,progressbar,&CircularProgressBar::_onTextChange);
    connect(slider,&QSlider::valueChanged,this,[=]{emit textChanged(QString("<div align='center' \
                                                                             style='\
                                                                               display: flex;\
                                                                               justify-content: center;\
                                                                               flex-flow: nowrap column;\
                                                                               color: #fff;\
                                                                             '\
                                                                           >\
                                                                             <div align='center'>\
                                                                               <strong style='text-transform: uppercase; font-size: x-small'>cpu</strong>\
                                                                               <span\
                                                                                 style='text-transform: uppercase; font-size: x-small; color: lightgray'\
                                                                               >\
                                                                                 usage</span\
                                                                               >\
                                                                             </div>\
                                                                             <div align='center'\
                                                                               style='\
                                                                                 display: flex;\
                                                                                 align-items: flex-start;\
                                                                                 font-size: 50px;\
                                                                                 color: #4daf7e; \
                                                                                 '\
                                                                             >\
                                                                             </br>\
                                                                               <span>%1</span>\
                                                                               <span align='center' style='font-size: 30px;'>%</span>\
                                                                             </div>\
                                                                           \
                                                                             <div align='center' style='font-size: x-small;'>\
                                                                               <span align='center' style='color: grey; text-transform: uppercase;'>temp</span>\
                                                                               <span align='center' style='color: lightgrey;'> 60</span>\
                                                                             </div>\
                                                                           </div>").arg(slider->value()));});

    frame->setLayout(layout);
    setCentralWidget(frame);

    frame->show();


}
