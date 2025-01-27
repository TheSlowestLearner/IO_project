#pragma once
#include <string>
#include <fstream>
/*
    W projekcie wymagany jest fstream i string aby klasa dzialala prawidlowo
*/

#define stats_number 3      //ilosc statystyk gracza
#define items_number 10     //ilosc itemow
#define start_stats_value 100 //poczatkowa wartosc statystyk gracza
class Player
{
public:
    Player()
    {
        for (int i = 0; i < stats_number; i++)
        {
            stats[i] = start_stats_value;
        }
        for (int i = 0; i < items_number; i++)
        {
            inventory[i] = 0;
        }
    }
    void modifyStats(int statId, int value)     //zmiana statystyk o wybrana wartosc
    {
        if (stats_number >= statId)
        {
            stats[statId] += value;
        }
        if (stats[statId] < -1)
            stats[statId] = -1;
    }
    int seeStats(int statId)    //podglad wartosci statystyk o podanym id   *zwrot wartosci -2 oznacza ze cos poszlo nie tak
    {
        if (stats_number >= statId)
        {
            return stats[statId];
        }
        return -2;
    }
    void modifyItem(int itemId, int value)     //zmiana ilosci itemu o wybrana wartosc
    {
        if (items_number >= itemId)
        {
            inventory[itemId] += value;
        }
    }
    int seeItems(int itemId)        //podglad ilosci itemu o podanym id     *zwrot wartosci -2 oznacza ze cos poszlo nie tak
    {
        if (items_number >= itemId)
        {
            return inventory[itemId];
        }
        return -2;
    }
    bool loadPlayer()           //wgrywanie gracza z pliku player.txt       *zwraca false jezeli cos poszlo nie tak
    {
        std::ifstream file;
        std::string line, number;
        int j = 0;
        file.open("player.txt");
        if (file.is_open())
        {
            while (getline(file, line))
            {
                int i = 0;
                while (i < line.size())
                {
                    number = "";
                    while (line[i] != ' ' && line[i] != '\n' && i < line.size())
                    {
                        number += line[i];
                        i++;
                    }
                    if (number != "" && stats_number <= j && j < stats_number + items_number)
                    {
                        inventory[j - stats_number] = stoi(number);
                        j++;
                    }
                    if (number != "" && j < stats_number)
                    {
                        stats[j] = stoi(number);
                        j++;
                    }
                    i++;
                }
            }
            file.close();
            return true;
        }
        else
            return false;
    }
    bool savePlayer()       //zapis stanu gracza do pliku player.txt    *zwraca false jezeli cos poszlo nie tak
    {
        std::fstream file;
        file.open("player.txt", std::ios::out);
        if (file.is_open())
        {
            std::string toFile;
            for (int i = 0; i < stats_number; i++)
            {
                toFile += std::to_string(stats[i]) + ' ';
            }
            file << toFile;
            file << '\n';
            toFile = "";
            for (int i = 0; i < items_number; i++)
            {
                toFile += std::to_string(inventory[i]) + ' ';
            }
            file << toFile;
            file << '\n';
            return true;
        }
        else
            return false;
    }
private:
    int stats[stats_number];	// statystyki gracza
    int inventory[items_number];		//ekwipunek
};