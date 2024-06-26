//#include <iostream>
//#include <string>
//using namespace std;
//
//
//string text = "Pheochromocytoma and paraganglioma are rare tumors arising from adrenal medullary "
//              "chromaffin cells or extraadrenal sympathetic neurons, respectively. In most other respects, "
//              "they are similar and are referred to collectively in this article as Pheo. "
//              "Approximately 800 new cases of Pheo are diagnosed annually in the United States. "
//              "Carcinoid is also a neuroendocrine tumor and shares several cytochemical features with Pheo. "
//              "For the treatment of Pheo and carcinoid, surgery, chemotherapy, and radiotherapy are used. "
//              "Once metastasis has occurred, treatment has met with limited success, and these treatments are themselves the cause of untoward side-effects. "
//              "A promising treatment, originally developed by investigators at the University of Michigan, is the use of metaiodobenzylguanidine (MIBG) labeled with iodine131."
//              "1–8 MIBG is accumulated by neuroendocrine cancer cells via the norepinephrine transporter. "
//              "Beta-particles emitted by 131I deliver energy that is cytotoxic; it is the combination of 131I cytotoxicity and MIBG target specificity that results in a selective, potentially lethal dose to tumor cells. "
//              "Iodine-131 also emits gamma photons that can be detected by using a gamma camera for imaging the distribution of the radiopharmaceutical";
//string separators = " ,!?:.\n\t-(){}[];";
//int const N = 4096;
//int const AMOUNT_OF_WORDS = 1;
//
//int amountOfShinglesFragment = 0;
//int carriage = 0;
//bool notTheEnd = true;
//string shinglesText[N] = {};
//string shinglesFragment[N] = {};
//
//int checkPlagiarism(string text, string fragment);
//int makeShinglesArray(string text, string shingles[], int index);
//bool compareShingles(string shingleText, string shingleFragment);
//int getStringLength(string str);
//double getTotalCoincidence(string fragment, string text);
//int countPlagiarism(int amountOfShinglesText, string& fragment, string shingle);
//void setShinglesNull(string shingle[N]);
//int roundedToInt(double num);
//int skipOneWord(string str, int index);
//string makeShingleFragment(string fragment);
//void removeShingle(string& fragment);
//void removeFirstWord(string& text);
//void changeFragment(string& fragment, bool deletedShingle);
//int calculatePlagiarism(string fragment, string text);
//int getAmountOfShingles(string shingles[]);
//
//void cleanStr(string& str);
//void replaceSeparatorsWithWhitespaces(string& str);
//bool isSeparator(char sym);
//void removeExcessSpaces(string& str);
//void removeArticles(string& str);
//void removePrepositions(string& str);
//void capitalize(string& str);
//void deleteSubstring(string& str, string& subStr);
//void deleteNonLatinSymbols(string& str);
//void deleteDuplicates(string& str);
//void copyStr(string& str1, string str2);
//bool isSame(string str1, string str2);
//void concatStr(string& str1, string str2);
//
//int main() {
//    string fragment = "Approximately 800 new cases of Pheo are diagnosed annually in the United States.";
//    int choice = 0;
//
//    cout << text << endl;
//    cout << endl;
//
//    while (true) {
//        cout << "1) Verify new fragment \n2) Exit" << endl;
//        cin >> choice;
//        if (choice == 1) {
//            cout << "Input your text:" << endl;
////            getline(cin, fragment);
////            getline(cin, fragment);
//            cout << "Your plagiarism percent: " << checkPlagiarism(text, fragment) << "%" << endl;
//        } else {
//            break;
//        }
//    }
//
//
//    return 0;
//}
//
//
//int checkPlagiarism(string text, string fragment){
//    double result = 0;
//
//    cleanStr(text);
//    cleanStr(fragment);
//    result = getTotalCoincidence(fragment, text);
//    return result;
//}
//
//void cleanStr(string& str) {
//
//    replaceSeparatorsWithWhitespaces(str);
//    removeExcessSpaces(str);
//    capitalize(str);
//    removeArticles(str);
//    removePrepositions(str);
//    deleteDuplicates(str);
//    deleteNonLatinSymbols(str);
//}
//
//int getStringLength(string str) {
//    int counter = 0;
//
//    while (true) {
//        if (str[counter] == '\0')
//            break;
//        counter++;
//    }
//    return counter + 1;
//}
//
//bool isSeparator(char sym) {
//    for (int i = 0; separators[i] != '\0'; i++) {
//        if (sym == separators[i])
//            return true;
//    }
//    return false;
//}
//
//void replaceSeparatorsWithWhitespaces(string& str) {
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (isSeparator(str[i]))
//            str[i] = ' ';
//    }
//}
//
//void removeExcessSpaces(string& str) {
//    string stack = "";
//
//    int spaceCounter = 0;
//    while (str[spaceCounter] == ' ') {
//        spaceCounter++;
//    }
//
//    for (int i = spaceCounter; str[i] != '\0'; i++) {
//        if (str[i] == ' ' and str[i + 1] == ' ')
//            continue;
//        else
//            stack += str[i];
//    }
//    int stackLength = getStringLength(stack);
//    if (stack[stackLength - 1] == ' ')
//        stack[stackLength - 1] = '\0';
//
//    copyStr(str, stack);
//}
//
//void capitalize(string& str) {
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] >= 'a' and str[i] <= 'z') {
//            str[i] = str[i] - 32;
//        }
//    }
//}
//
//void deleteSubstring(string& str, string& subStr) {
//    string tempWord = "";
//    string stack = "";
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] != ' ') {
//            tempWord += str[i];
//        }
//        else if (!isSame(tempWord, subStr)) {
//            stack += tempWord + " ";
//            tempWord = "";
//        }
//        else {
//            tempWord = "";
//        }
//    }
//    if (!isSame(tempWord, subStr)) {
//        concatStr(stack, tempWord);
//        tempWord = "";
//        }
//
//    copyStr(str, stack);
//}
//
//void removeArticles(string& str) {
//    int const nOfArticles = 3;
//
//    string articles[nOfArticles] = {"AN", "THE", "A"};
//    for (int i = 0; i < nOfArticles; i++){
//        deleteSubstring(str, articles[i]);
//    }
//}
//
//void removePrepositions(string& str) {
//    int const nOfPrepositins = 11;
//    string prepositions[nOfPrepositins] = {"AT", "BY", "AS", "IN", "FROM", "INTO", "AT", "FOR", "FROM", "ON", "OF"};
//    for (int i = 0; i < nOfPrepositins; i++){
//        deleteSubstring(str, prepositions[i]);
//    }
//}
//
//void deleteDuplicates(string& str) {
//    string tempWord = "";
//    string preTempWord = "";
//    string stack = "";
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] != ' ') {
//            tempWord += str[i];
//        }
//        else if (str[i] == ' ') {
//            if (tempWord != preTempWord) {
//                stack += tempWord + " ";
//            }
//            preTempWord = tempWord;
//            tempWord = "";
//        }
//        if (str[i + 1] == '\0') {
//            stack += tempWord;
//        }
//    }
//    copyStr(str, stack);
//}
//
//void deleteNonLatinSymbols(string& str) {
//    string tempWord = "";
//    string stack = "";
//
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] != ' ') {
//            tempWord += str[i];
//            if ((str[i] < 'A' or str[i] > 'Z')and str[i] != '\'') {
//                tempWord = "";
//                continue;
//            }
//        }
//        else if (str[i] == ' ') {
//            stack += tempWord + " ";
//            tempWord = "";
//        }
//        if (str[i + 1] == '\0') {
//            concatStr(stack, tempWord);
//        }
//    }
//    copyStr(str, stack);
//}
//
//bool isSame(string str1, string str2) {
//    int len1 = getStringLength(str1);
//    int len2 = getStringLength(str2);
//    bool isSameStrings = false;
//
//    if (len1 == len2) {
//        isSameStrings = true;
//        for (int i = 0; str1[1] != '\0'; i++) {
//            if (str1[i] != str2[i])
//                isSameStrings = false;
//            break;
//        }
//    }
//    return isSameStrings;
//}
//
//int makeShinglesArray(string text, string shingles[], int index) {
//    int spaces = 0;
//    int iShingle = 0;
//
//    for (int i = index; text[i] != '\0';) {
//        if (text[i] == '\0')
//            break;
//        for (int spaces = 0; spaces < AMOUNT_OF_WORDS;) {
//            if (text[i] == ' '){
//                while (text[i + 1] == ' ')
//                    i++;
//                spaces++;
//            }
//            else if (text[i] == '\0')
//                break;
//            else
//                shingles[iShingle] += text[i];
//            i++;
//        }
//        iShingle++;
//    }
//    return iShingle;
//}
//
//bool compareShingles(string shingleText, string shingleFragment) {
//    if (getStringLength(shingleText) != getStringLength(shingleFragment))
//        return false;
//    for (int i = 0; shingleFragment[i] != 0; ++i) {
//        if (shingleFragment[i] != shingleText[i])
//            return false;
//    }
//    return true;
//}
//
//double getTotalCoincidence(string fragment, string text) {
//    double total = 0.0;
//    int plagiarism = 0;
//    int amountOfShinglesText = 0;
//    int indexText = 0;
//    int indexFragment = 0;
//    int totalAmountOfShingles = 0;
//    string shingle = "";
//    bool deletedShingle = false;
//
//    amountOfShinglesFragment = makeShinglesArray(fragment, shinglesFragment, indexFragment);
//    while (notTheEnd) {
//        shingle = makeShingleFragment(fragment);
//
//        for (int i = 0; i < AMOUNT_OF_WORDS; ++i) {
//            amountOfShinglesText = makeShinglesArray(text, shinglesText, indexText);
//            plagiarism = countPlagiarism(amountOfShinglesText, fragment, shingle);
//            total += plagiarism;
//            setShinglesNull(shinglesText);
//            indexText = skipOneWord(text, indexText);
//
//            if (plagiarism){
//                deletedShingle = true;
//                break;
//            }
//        }
//        changeFragment(fragment, deletedShingle);
//        shingle="";
//        deletedShingle = false;
//    }
//    return total / amountOfShinglesFragment * 100.0;
//}
//
//void copyStr(string& str1, string str2) {
//    char copy[N] = {};
//    int i = 0;
//    for(i = 0; str2[i] != '\0'; ++i) {
//        copy[i] = str2[i];
//    }
//    copy[i] = '\0';
//    str1 = copy;
//}
//
//void concatStr(string& str1, string str2) {
//    char copy[N] = {};
//    int i = 0;
//    int j = 0;
//    for (i = 0; str1[i] != '\0'; i++) {
//        copy[i] = str1[i];
//    }
//    for (j = 0; str2[j] != '\0'; j++) {
//        copy[i] = str2[j];
//        i++;
//    }
//    copy[i] = '\0';
//    str1 = copy;
//}
//
//int skipOneWord(string str, int index){
//    int i = index;
//
//    while (str[i] != ' '){
//        i++;
//    }
//
//    while (str[i] == ' ')
//        i++;
//
//    return i;
//}
//int countPlagiarism(int amountOfShinglesText, string& fragment, string shingle) {
//    int plagiarism = 0;
//
//    for (int j = 0; j < amountOfShinglesText; ++j) {
//            if (compareShingles(shinglesText[j], shingle)){
//                plagiarism++;
//                break;
//            }
//    }
//    return plagiarism;
//}
//
//void setShinglesNull(string shingle[N]){
//    for (int i = 0; i < N ; ++i) {
//        shingle[i] = "";
//    }
//}
//
//int roundedToInt(double num){
//    int result = 0;
//
//    result = num + 0.5;
//
//    return result;
//}
//
//string makeShingleFragment(string fragment){
//    string shingle;
//    int spaces = 0;
//
//    while (fragment[carriage] == ' ')
//        carriage++;
//    for (int spaces = 0; spaces < AMOUNT_OF_WORDS;) {
//        if (fragment[carriage] == ' '){
//            while (fragment[carriage + 1] == ' ')
//                carriage++;
//            spaces++;
//        }else if (fragment[carriage] == '\0'){
//            notTheEnd = false;
//            break;
//        }else
//            shingle += fragment[carriage];
//        carriage++;
//    }
//
//    return shingle;
//}
//
//void removeShingle(string& fragment){
//    for (int i = 0; i < carriage - 1; ++i) {
//        fragment[i] = ' ';
//    }
//    carriage = 0;
//}
//
//void removeFirstWord(string& text){
//    int index = 0;
//    while (text[index] == ' ')
//        index++;
//    while (text[index] != ' '){
//        text[index] = ' ';
//        index++;
//    }
//    carriage = index;
//}
//
//void changeFragment(string& fragment, bool deletedShingle){
//    if (!deletedShingle)
//        removeFirstWord(fragment);
//    else
//        removeShingle(fragment);
//}
//
////int calculatePlagiarism(string fragment, string text){
////    int result = 0;
////    double totalCoincidence = 0.0;
////
////    totalCoincidence = getTotalCoincidence(fragment,text);
////    result = roundedToInt(totalCoincidence / amountOfShinglesFragment * 100.0);
////
////    return result;
////}
//
////int getAmountOfShingles(string shingles[]){
////    int amountOfShingles = 0;
////    for (int i = 0; shingles[i] != ""; ++i) {
////        amountOfShingles++;
////    }
////    return amountOfShingles;
////}