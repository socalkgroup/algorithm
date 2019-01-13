
int numberOfIslands(vector<vector<int>>& input) {
    int ret = 0 ;
    for(int i = 0; i < input[0].size(); i++) {
        for(int j = 0; j < input.size(); j++) {

            if(input[y][x]!=1) {
                continue;
            }

            ret++;
            checkAdjacent(input, i,j);
        }
    }
    return ret;
}

void checkAdjacent(vector<vector<int>>& input, int x, int y) {
      // check boundaries
	if(y < 0 || y >= input.size() || x < 0 || x >= input[0].size()) {
		return;
	}
      
    if(input[y][x] == 1) {
        Input[y][x] = 2;
        checkAdjacent(input, x-1, y);
        checkAdjacent(input, x, y-1);
        checkAdjacent(input, x+1, y);
        checkAdjacent(input, x, y+1);
    }
}
