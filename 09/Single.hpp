class Single {
public:
	static Single* getInstance();
private:
	Single();
	static Single* instance;
};