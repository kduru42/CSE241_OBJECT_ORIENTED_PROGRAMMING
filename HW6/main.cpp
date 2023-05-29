#include "Application.h"

int main()
{
    File f;
    string type = f.read_type();
    if (type == "movie")
    {
        Application<Movie> app("movie");
        app.read_datas();
        app.read_commands();
    }
    else if (type == "book")
    {
        Application<Book> app("book");
        app.read_datas();
        app.read_commands();
    }
    else if (type == "music")
    {
        Application<Music> app("music");
        app.read_datas();
        app.read_commands();
    }
}