#ifndef REGISTREBORNEGUI_H
#define REGISTREBORNEGUI_H

#include <string>
#include <QtGui/QMainWindow>
#include "ui_registrebornegui.h"
#include "RegistreBorne.h"

class RegistreBorneGUI : public QMainWindow
{
    Q_OBJECT

public:
    RegistreBorneGUI(QWidget *parent = 0);
    ~RegistreBorneGUI();
    void affichageBorne(tp::Borne* borne);

private slots:
	void afficheFontaineForm();
	void afficheStationnementForm();

private:
    Ui::RegistreBorneGUIClass ui;
    tp::RegistreBorne registre;
    enum
	{
    	ID, NOM
	};
};

#endif // REGISTREBORNEGUI_H
