#include "../incl/Converter_JSON.h"
#include "../incl/Inverted_Index.h"
#include "../incl/Search_Server.h"


int main(int argc, char* argv[])
{
    Converter_JSON json_file;
    json_file.start();
    if(!json_file.get_state())
    {
        std::cerr << "Chek the path configuration direction" << std::endl;
        return -1;
    }
    Inverted_Index ind;
    ind.update_Document_Base(json_file.get_Text_Document());

    Search_Server serv(ind);
    serv.set_response_limit(json_file.get_Response_Limit());
    std::vector<std::vector<Relative_Index>>
    answere = serv.search(json_file.get_Request());
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
    json_file.put_Answere(j_answere);
    return 0;
}