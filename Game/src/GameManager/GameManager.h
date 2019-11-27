class GameManager
{
    private:
    
        GameManager(){}
    
    public:
        ~GameManager(){}
        static GameManager* getInstance(){
            static GameManager only_instance;
            return &only_instance;
        }
        void initAll();
        void clear();
        void updateAll(float dt);
};