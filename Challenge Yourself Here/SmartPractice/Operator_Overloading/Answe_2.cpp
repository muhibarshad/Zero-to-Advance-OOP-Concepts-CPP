#include<iostream>

using namespace std;

class MatchScore{
	int score;
	int numOfBalls;
	float sR;
	bool out;
	static int totalScore;
	static int totalBalls;
	static int totalOut;
	
  public:
   	
   	MatchScore( int score, int balls, float sR, bool out )
	{
   		setScore(score);
   		setBalls(balls);
   		setSR(sR);
   		
   		this->out = out;
   		if ( out )
   			totalOut++;
	}
	
	void setScore( int s )
	{
		if ( s >= 0 )
		{
			score = s;
			totalScore += s;
		}
		else 
			score = 0;		
	}
	
	void setBalls( int b )
	{
		if ( b >= 1 )
		{
			numOfBalls = b;
			totalBalls += b;
		}
		else 
			numOfBalls = 0;		
	}
	
	void setSR( float s )
	{
		if ( s >= 100 )
			sR = s;
		else 
			sR = 0;	
	}
	
	void show() const
	{
		cout << score << "\t" <<numOfBalls << "\t\t" << sR << "\t\t";
		if ( out )
			cout << "OUT";
		else 
			cout << "NOT OUT";
		
		cout << '\n';
	}
	
	static int getTotalScore()
	{
		return totalScore;
	}
	
	static int getTotalBallsPlayed()
	{
		return totalBalls;
	}
	
	static int getTotalPlayersOut()
	{
		return totalOut;
	}
	
	static float getAverageStrikeRate()
	{
		return (float)totalScore / totalBalls * 100;
	}
	
};

int MatchScore :: totalScore = 0;
int MatchScore :: totalBalls = 0;
int MatchScore :: totalOut = 0;

int main()
{
	MatchScore players[11] = { MatchScore(12, 8, 150, 1), MatchScore(20, 10, 200.21, 1 ), MatchScore(30, 24, 125.56, 0), MatchScore(60, 34, 176.47, 0), MatchScore(95, 65, 146.11, 1), MatchScore(65, 54, 120.32, 0), MatchScore(90, 75, 120.00, 0), MatchScore(36, 25, 144.92, 1), MatchScore(10, 10, 100.00, 1), MatchScore(23, 15, 154.25, 0), MatchScore(114, 72, 158.33, 1) };
	int i;
	
	cout << "Score\tBalls Played\tStrike Rate\tOut/Not Out\n\n";
	
	for ( i = 0; i < 11; i++ )
	{
		players[i].show();
	}
	
	cout << "\nTotal Score: " << MatchScore :: getTotalScore();
	cout << "\nTotal Balls Played: " << MatchScore :: getTotalBallsPlayed();
	cout << "\nTotal Players Out: " << MatchScore :: getTotalPlayersOut();
	cout << "\nAverage Strike Rate: " << MatchScore :: getAverageStrikeRate();
	
	
	return 0;
}