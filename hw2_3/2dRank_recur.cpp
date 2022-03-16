    #include <iostream>
    #include <set>
    using namespace std;
    typedef pair< signed  int,  signed int > Pos;
    int record[300000];
        
    void entry_ranking(set< pair<Pos,unsigned> >pool){
        if (pool.size() <= 1)
            return;
        double  sum = 0, mid_linex = 0;
        set< pair<Pos,unsigned> > left, right;
        set< pair<Pos,unsigned> >::iterator itr;
        for (itr = pool.begin(); itr != pool.end(); itr++)
        {
            //calculate mid line of x
            sum+= itr->first.first;
        }
        mid_linex = sum / pool.size();
        //split into two parts by mean x
        for (itr = pool.begin(); itr != pool.end(); itr++)
        {
            if (itr->first.first < mid_linex)
            {
                left.insert(*itr);
            }
            else
            {
                right.insert(*itr);
            }
        }
        if(left.size()==0 )
            goto comb;
        entry_ranking(left);
        entry_ranking(right);
        
        //combine
        comb:
        // cout<<"go here"<<endl;
        set<pair<Pos, unsigned>>::iterator L_itr, R_itr;
        int rk_counter = 0;
        if (left.size())
        {
            //sort y(by reverse the position)
            set< pair<Pos,unsigned> > temp_left, temp_right;
            for (L_itr = left.begin(); L_itr != left.end(); L_itr++){
                temp_left.insert(pair<Pos, unsigned>(Pos(L_itr->first.second, L_itr->first.first), L_itr->second));
            }
            for (R_itr = right.begin(); R_itr != right.end(); R_itr++){
                
                temp_right.insert(pair<Pos,unsigned> (Pos(R_itr->first.second,R_itr->first.first),R_itr->second));
            }

            L_itr = temp_left.begin();
            R_itr = temp_right.begin();
            left.clear();
            right.clear();
            //start update ranking
            while (L_itr != temp_left.end() && R_itr != temp_right.end())
            {
                
                if ((L_itr)->first.first <= (R_itr)->first.first &&(L_itr)->first.second < (R_itr)->first.second)
                {
                    rk_counter++;
                    L_itr++;
                }
                else
                {
                    record[(R_itr)->second] += rk_counter;
                    // cout<<"record[(R_itr)->second]"<<" "<<record[(R_itr)->second]<<endl;
                    R_itr++;
                }
            }
            
            while ( R_itr != temp_right.end())
            {
                record[(R_itr)->second] += rk_counter;
                // cout<<"record[(R_itr)->second]"<<" "<<record[(R_itr)->second]<<endl;
                R_itr++;
            }
            temp_left.clear();
            temp_right.clear();
            
        }
        else
        { // all pos are on the right side
            for (R_itr = right.begin(); R_itr != right.end(); R_itr++)
            {
                record[(R_itr)->second] += rk_counter;
                rk_counter++;
            }
        }
            left.clear();
            right.clear();
    }

    int main()
    {
        unsigned int N;
        signed  int x, y;
        set<pair<Pos,unsigned> > pool;
        cin >> N;

        for (unsigned int i = 0; i < N; i++)
        {
            cin >> x >> y;
            pool.insert(pair<Pos, unsigned>(Pos(x, y), i));
            record[i] = 0;
        }
        entry_ranking(pool);
        for (unsigned int i = 0; i < N; ++i)
                cout << record[i] << " ";

        return 0;
    }