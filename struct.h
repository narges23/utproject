struct users{
	char* name;
	char* pass;
	struct users *next;
};

struct post {
	char *name;
	char* text;
	int post_id;
	int like;
	struct post *next;
};
