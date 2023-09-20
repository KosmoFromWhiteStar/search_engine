#ifndef SEARCH_ENGINE_QT_MAIN_H
#define SEARCH_ENGINE_QT_MAIN_H
#include <QApplication>
#include <QMainWindow>
#include <QtWidgets/QFileDialog>

#include "../incl/Converter_JSON.h"
#include "../incl/Inverted_Index.h"
#include "../incl/Search_Server.h"
#include "./res/ui_search_window.h"





class Qt_main : public  QMainWindow
{
    Q_OBJECT

private:
    Converter_JSON* json_file;
    Inverted_Index ind;
    bool state = false;
    js j;
    std::vector<std::vector<Relative_Index>> answere;
    Ui::MainWindow win;

public:
    Qt_main(QWidget* parent = nullptr) : QMainWindow(parent) {
        win.setupUi(this);
    }
    QString file_path;
    ~Qt_main()
    {
        delete json_file;
    }
public slots:
    void config()
    {
        file_path = QFileDialog::getExistingDirectory( nullptr, tr("Open Directory"),
                                                       ".",QFileDialog::ShowDirsOnly);
        json_file = new Converter_JSON(file_path.toStdString() + "/");
        if(json_file->get_Response_Limit() == 0)
        {
            state = false;
            return;
        }
        state = true;
        json_file->start();
        ind.update_Document_Base(json_file->get_Text_Document());

        std::string temp = "Start\n";
        temp += "Requestion: \n";
        for(int i = 0; i < json_file->get_Request().size(); i++)
        {
            temp += "#" + std::to_string(i) + '\t' + json_file->get_Request()[i] + '\n';
        }
        j = json_file->get_js();
        win.output->setText(QString::fromStdString(temp));
    }
    void search()
    {
        if(!state)
        {
            std::cout << "Something wrong" << std::endl;
            return;
        }
        Search_Server serv(ind);
        serv.set_response_limit(json_file->get_Response_Limit());
        answere = serv.search(json_file->get_Request());
        win.output->setText("Searched");
    }
    void save()
    {
        if(!state)
        {
            std::cout << "Something wrong" << std::endl;
            return;
        }
        std::vector<std::vector<std::pair<size_t, float>>> j_answere(answere.size());
        //
        for(int i = 0; i < j_answere.size();i++)
        {
            j_answere[i].resize(answere[i].size());
            for(int j = 0; j < j_answere[i].size(); j++)
            {
                j_answere[i][j].first = answere[i][j].doc_id;
                j_answere[i][j].second = answere[i][j].rank;
            }
        }
        //
        json_file->put_Answere(j_answere);
        win.output->setText(QString::fromStdString("Saved"));
    }

};


#endif //SEARCH_ENGINE_QT_MAIN_H
