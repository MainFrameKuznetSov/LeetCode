class Spreadsheet {
public:

    unordered_map<string,int>cellData;

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        cellData[cell]=value;
    }
    
    void resetCell(string cell) {
        cellData[cell]=0;
    }
    
    int getValue(string formula) {
        int pos=formula.find('+');
        string fpart=formula.substr(1,pos-1);
        string lpart=formula.substr(pos+1);
        //cout<<fpart<<" "<<lpart<<"\n";
        if(isalpha(fpart[0]))
        {
            if(isalpha(lpart[0]))
                return cellData[fpart]+cellData[lpart];
            return cellData[fpart]+stoi(lpart);
        }
        else
        {
            if(isalpha(lpart[0]))
                return stoi(fpart)+cellData[lpart];
            return stoi(fpart)+stoi(lpart);
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */