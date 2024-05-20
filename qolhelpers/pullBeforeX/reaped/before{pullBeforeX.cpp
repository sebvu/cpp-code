int main() 
    while (true) 
        if (!file.is_open()) 
        } else 
    while (true) 
        if (reapWhere != 1 && reapWhere != 2) 
        } else 
    switch (reapWhere) 
    try 
        if (!reapFile.is_open()) 
        while (getline(file, currentLine)) 
            if (delimeterPos == -1) 
            } else 
                switch (reapWhere) 
    } catch (std::out_of_range &e) 
    } catch (std::runtime_error &e) 
