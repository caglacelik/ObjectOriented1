#include "input.h"

void Input::readInputs(string filename)
{
    
    TankList t;
    int pos;
    string delimiter = ";";
    string line;
    vector<string> lines;
    ifstream inputFile;
    inputFile.open(filename);
    int i;
    
    if (!inputFile)
    {
        cout << "Error opening the file" << endl;
    }
    while (getline(inputFile, line)) { /// Reading file line by line.
        if (line.find(delimiter) != -1) { /// ";" Read line until delimiter.
            pos = line.find(delimiter);
            lines.push_back(line.substr(0, pos));
            line = line.substr(pos + delimiter.length());
        }
    }
    for (int i = 0; i < lines.size(); i++) { /// Pushing the elements into the array.
        if (isspace(lines[i].at(0)))
            lines[i] = lines[i].substr(1);
        lines[i] += ";";
    }
    
    
    Engine& e = Engine::Get();
    cout << e.get_status() << endl;
    e.start_engine();

    double doubleValue;
    string temp;
    int sizeoftemp;
    string cmnd;
    for (i = 0; i < lines.size(); i++)
    {
        temp = lines[i];

        vector<string> out;
        vector<string> output;

        if (isStringNeedValue(temp) == true)   /// Is string need command? If it is, return true.
        {
            /// Take the command only.
            tokenize(temp, '<', out);
            cmnd = out[0];
            cmnd = remove_spaces(cmnd);


            ///   Setting value string the parameter in the <  > .
            pos = temp.find("<");
            string value = temp.substr(pos + 1);
            tokenize(value, '>', output);
            value = output[0];



            ///Converting string value to the double value
            doubleValue = atof(value.c_str());



            /// Comparing the command names and calling the functions.
            if (cmnd == "absorb_fuel")
            {
                e.absorb_fuel(doubleValue);
            }

            else if (cmnd == "give_back_fuel")
            {
                e.give_back_fuel(doubleValue);
            }

            else if (cmnd == "add_fuel_tank")
            {
                t.add_fuel_tank(doubleValue);
            }

            else if (cmnd == "remove_fuel_tank")
            {
                t.remove_fuel_tank(doubleValue);
            }

            else if (cmnd == "connect_fuel_tank_to_engine")
            {
                t.connect_fuel_tank_to_engine(doubleValue);
            }
            else if (cmnd == "disconnect_fuel_tank_from_engine")
            {
                t.disconnect_fuel_tank_from_engine(doubleValue);
            }
            else if (cmnd == "open_valve")
            {
                t.open_valve(doubleValue);
            }
            else if (cmnd == "close_valve")
            {
                t.close_valve(doubleValue);
            }
            else if (cmnd == "break_fuel_tank")
            {
                t.break_fuel_tank(doubleValue);
            }
            else if (cmnd == "repair_fuel_tank")
            {
                t.repair_fuel_tank(doubleValue);
            }

        }
        else
        {
            tokenize(temp, ';', out);
            cmnd = out[0];
            if (cmnd == "start_engine")
            {
                e.start_engine();
            }
            else if (cmnd == "stop_engine")
            {
                e.stop_engine();
            }
            else if (cmnd == "list_fuel_tanks")
            {
                t.list_fuel_tanks();
            }
            else if (cmnd == "stop_simulation")
            {
                e.stop_simulation();
            }

        }
    }

    inputFile.close(); /// close input file
}


string Input::remove_spaces(const string& s)
{
    ///Removing spaces and returning string without spaces.
    int last = s.size() - 1;
    while (last >= 0 && s[last] == ' ')
        --last;
    return s.substr(0, last + 1);
}


void Input::tokenize(std::string const& str, const char delim,std::vector<std::string>& out)
{
    /// Tokenizing the string.
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}


bool Input::isStringNeedValue(string str)
{
    /// If string need value ( there is < > in the line string), returns true.
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '<')
        {
            return true;
        }
    }
    return false;
}