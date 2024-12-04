#include "_shaders.h"

_shaders::_shaders()
{
    //ctor
}

_shaders::~_shaders()
{
    //dtor
    cleanUp();
}

void _shaders::loadFiles(char* fileName, string& str)
{
    char tmp[1024];

    ifstream in(fileName);
    if(!in.is_open())
    {
        cout <<"File could not open."<< endl;
        return;
    }

    while(!in.eof())
    {
        in.getline(tmp, 1024);
        str += tmp;
        str += '\n';
    }
    cout << str << endl;        //for debugging
}

unsigned int _shaders::loadShader(string& source, unsigned int mode)
{
    unsigned int id;
    const char * cSource;
    char error[1024];

    id = glCreateShader(mode);
    cSource = source.c_str();

    glShaderSource(id,1,&cSource,NULL);
    glCompileShader(id);

    glGetShaderInfoLog(id,1024,NULL,error);
    cout << "Compile Status : \n" << error << endl;

    return id;

}

void _shaders::initShader(char* vFileName, char* fFileName)
{
    string source;
    loadFiles(vFileName, source);
    vs = loadShader(source, GL_VERTEX_SHADER);

    source = "";
    loadFiles(fFileName, source);
    fs = loadShader(source, GL_FRAGMENT_SHADER);

    program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

}

void _shaders::cleanUp()
{
    glDetachShader(program, vs);
    glDetachShader(program, fs);
    glDeleteShader(vs);
    glDeleteShader(fs);
    glDeleteProgram(program);

}
