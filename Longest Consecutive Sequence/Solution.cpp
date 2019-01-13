int lognestConsecutiveSequence(const vector<int>& input) {

   unordered_map<int,int> nmap;
   int maxConsecutive = 0;

   for(int i = 0 ; i < input.size(); i++) {
       if (nmap.find(input[i]) == nmap.end()) {
           nmap.insert(make_pair(input[i], 1));
       }
   }

   for(int i = 0 ; i < input.size(); i++) {
       if (nmap.find(input[i]-1) == nmap.end()) {
           int currentSeq = 0 ;
           for(int pos = input[i];;pos++) {
               if(nmap.find(pos) != nmap.end()) {
                   maxConsecutive = std::max(++currentSeq, maxConsecutive);
               }
               else {
                 break;
               }
           }
       }
   }
   return maxConsecutive;
}