#include"RubiksCube.h"

class RubiksCube3dArray : public RubiksCube {
    private:
       char cube[6][3][3];
       void rotateFace(int id){
        char temp_face[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp_face[i][j]=cube[id][i][j];
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cube[id][i][j]=temp_face[2-j][i];
            }
        }

       }
    public:
       RubiksCube3dArray(){
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k]=getColorLetter(static_cast<COLOR>(i));
                }
            }
       }

       COLOR getColor(FACE face,unsigned row,unsigned col) const override { 
        return static_cast<COLOR>(cube[static_cast<int>(face)][row][col]);
       }

        bool isSolved() const override {
            for(int i=0;i<6;i++){
                for(int j=0;j<3;j++){
                    for(int k=0;k<3;k++){
                        if(cube[i][j][k]!=getColorLetter(static_cast<COLOR>(i))){
                            return false;
                        }
                    }
                    }
                }
            }
            return true;
        }

        RubiksCube3dArray& move(MOVE ind) override{
            switch(ind){
                case MOVE::L:
            }
        }

        RubiksCube &u() override{{
            this->rotateFace(0);
            char temp[3]={};

            for(int i=0;i<3;i++){
                temp[i]=cube[1][0][i];
            }

            for(int i=0;i<3;i++) cube[1][0][i]=cube[2][i][0];

            for(int i=0;i<3;i++) cube[2][i][0]=cube[3][0][i];

            for(int i=0;i<3;i++) cube[3][0][i]=cube[4][0][i];

            for(int i=0;i<3;i++) cube[4][0][i]=temp[i];

            return *this;
        
        }
        RubiksCube &uPrime() override{
            this->u();
            this->u();
            this->u();
            return *this;
        }

        RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
        }

        RubiksCube &l() override{
            this->rotateFace(1);
            char temp[3]={};

            for(int i=0;i<3;i++) temp[i]=cube[0][i][0];

            for(int i=0;i<3;i++) cube[0][i][0]=cube[4][i][0];

            for(int i=0;i<3;i++) cube[4][i][0]=cube[5][i][0];

            for(int i=0;i<3;i++) cube[5][i][0]=cube[2][i][0];

            for(int i=0;i<3;i++) cube[2][i][0]=temp[i];

            return *this;
            
        }
        RubiksCube &lPrime() override{
            this->l();
            this->l();  
            this->l();
            return *this;
        }
        RubiksCube &l2() override{
            this->l();
            this->l();
            return *this;
        }

        RubiksCube &f() override{
            this->rotateFace(2);
            char temp[3]={};
            for(int i=0;i<3;i++) temp[i]=cube[0][2][i];
            for(int i=0;i<3;i++) cube[0][2][i]=cube[1][2][i];
            for(int i=0;i<3;i++) cube[1][2][i]=cube[5][2][i];
            for(int i=0;i<3;i++) cube[5][2][i]=cube[3][2][i];
            for(int i=0;i<3;i++) cube[3][2][i]=temp[i];
            return *this;
        }

        RubiksCube &fPrime() override{
            this->f();
            this->f();      
            this->f();
            return *this;
        }

        RubiksCube &f2() override{
            this->f();
            this->f();
            return *this;
        }

        RubiksCube &r() override{
            this->rotateFace(3);
            char temp[3]={};
            for(int i=0;i<3;i++) temp[i]=cube[0][i][2];
            for(int i=0;i<3;i++) cube[0][i][2]=cube[2][i][2];
            for(int i=0;i<3;i++) cube[2][i][2]=cube[5][i][2];
            for(int i=0;i<3;i++) cube[5][i][2]=cube[4][i][2];
            for(int i=0;i<3;i++) cube[4][i][2]=temp[i];
            return *this;
        }

        RubiksCube &rPrime() override{
            this->r();
            this->r();
            this->r();
            return *this;
        }

        RubiksCube &r2() override{
            this->r();
            this->r();
            return *this;
        }
        RubiksCube &b() override{
            this->rotateFace(4);
            char temp[3]={};
            for(int i=0;i<3;i++) temp[i]=cube[0][0][i];
            for(int i=0;i<3;i++) cube[0][0][i]=cube[3][0][i];
            for(int i=0;i<3;i++) cube[3][0][i]=cube[5][0][i];
            for(int i=0;i<3;i++) cube[5][0][i]=cube[1][0][i];
            for(int i=0;i<3;i++) cube[1][0][i]=temp[i];
            return *this;
        }

        RubiksCube &bPrime() override{
            this->b();
            this->b();
            this->b();
            return *this;
        }

        RubiksCube &b2() override{
            this->b();
            this->b();
        }

        RubiksCube &d() override{
            this->rotateFace(5);
            char temp[3]={};
            for(int i=0;i<3;i++) temp[i]=cube[1][2][i];
            for(int i=0;i<3;i++) cube[1][2][i]=cube[4][2][i];
            for(int i=0;i<3;i++) cube[4][2][i]=cube[3][2][i];
            for(int i=0;i<3;i++) cube[3][2][i]=cube[2][2][i];
            for(int i=0;i<3;i++) cube[2][2][i]=temp[i];
            return *this;
        }

        RubiksCube &dPrime() override{
            this->d();
            this->d();
            this->d();
            return *this;
        }

        RubiksCube &d2() override{
            this->d();
            this->d();
        }
         bool operator==(const RubiksCube3dArray &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubiksCube3dArray &operator=(const RubiksCube3dArray &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const RubiksCube3dArray &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }

};
