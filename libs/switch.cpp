using namespace std;

class Opts{
    public:
        const string arr[3] = {"quit","search","dico"};
        int cmd(string cmd) {
            int compt = 0;
            for (const string& i : arr) {
                if (cmd == i) {
                return compt;
                }
                compt++;
            }
            return 404;
        }
};