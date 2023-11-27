<h1>中國象棋</h1>
<h2>遊戲介紹</h2>
<p>象棋是中國大陸、香港、台灣、馬來西亞、新加坡、越南、琉球地區所流行的傳統的2人對弈棋類遊戲。中國大陸為了進行區分稱此為中國象棋，將西方的「Chess」稱為國際象棋；台灣將「Chess」翻譯為「西洋棋」。類似的中國象棋的還有韓國將棋、日本將棋等。韓國將棋起源於中國象棋, 是中國象棋的一種。日本將棋或起源於唐代寶應象棋。

中國象棋與西洋棋及圍棋並列世界三大棋類之一。象棋主要流行於全球華人、越南人及琉球人社區，是首屆世界智力運動會的正式比賽項目之一。</p>
<div align="right" >來源-<a href="https://zh.wikipedia.org/zh-tw/%E8%B1%A1%E6%A3%8B">Wiki</a></div>
<h2>遊戲規則</h2>
<h3>棋盤與棋子</h3>
<p>棋盤為橫九縱十的方格，在格子的交叉點上放置棋子。每位玩家的棋子有16枚，分別為將、士、象、車、馬、砲、兵。</p>
<h3>旗子移動</h3>
<table>
  <thead>
    <tr>
      <th>圖案</th>
      <th>棋子數</th>
      <th>活動範圍</th>
      <th>走法</th>
      <th>備註</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/6/69/Xiangqi_gd1.svg"><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/5/50/Xiangqi_gl1.svg"></td>
      <td>1</td>
      <td>九宮格內</td>
      <td>前後左右各走一步</td>
      <td>主要棋子</td>
    </tr>
    <tr>
      <td><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/f/f5/Xiangqi_ad1.svg"><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/e/ed/Xiangqi_al1.svg"></td>
      <td>2</td>
      <td>九宮格內</td>
      <td>對角線各走一步</td>
      <td>保護帥/將</td>
    </tr>
    <tr>
      <td><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/1/1a/Xiangqi_ed1.svg"><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/7/77/Xiangqi_el1.svg"></td>
      <td>2</td>
      <td>自家內</td>
      <td>田字/td>
      <td>不能過河，不得拐相腳</td>
    </tr>
    <tr>
      <td><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/9/9d/Xiangqi_hd1.svg"><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/0/04/Xiangqi_hl1.svg"></td>
      <td>2</td>
      <td>走日字</td>
      <td>日字形走法</td>
      <td>不得拐馬腳</td>
    </tr>
    <tr>
      <td><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/f/f7/Xiangqi_rd1.svg"><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/2/2e/Xiangqi_rl1.svg"></td>
      <td>2</td>
      <td>直線橫豎</td>
      <td>直線走法</td>
      <td>最大行動範圍</td>
    </tr>
    <tr>
      <td><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/4/43/Xiangqi_cd1.svg"><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/1/1f/Xiangqi_cl1.svg"></td>
      <td>2</td>
      <td>直線橫豎</td>
      <td>跳躍1子後隔一子吃子</td>
      <td>可隔子吃子</td>
    </tr>
    <tr>
      <td><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/0/03/Xiangqi_sd1.svg"><img width=60px height= 60px src="https://upload.wikimedia.org/wikipedia/commons/0/0f/Xiangqi_sl1.svg"></td>
      <td>5</td>
      <td>前進1步，過河後可左右移動</td>
      <td>過河後能左右移動</td>
      <td>過河可進升</td>
    </tr>
  </tbody>
</table>
</tablet>
<p>玩家輪流行動，被吃掉將就輸了</p>
<h2>程式結構圖</h2>
<h3>各個函式</h3>
<p>main.c</p>
<ul>
  <li>clr<br>負責清除畫面，並在main中會被重複呼叫 ，搭配 inputansselect</li> 
  <li>init<br>初始化象棋棋盤</li>
  <li>setColor<br>使用windows.h的函式庫，改變棋盤的顏色</li>
  <li>cheesename<br>負責將cheesename陣列的數字內容轉換為各個象棋的名字</li>
  <li>cheeseboard<br>負責將row 和 col 轉換為陣列的棋盤內容，並在送出給cheesename最後return該棋的中文字</li>
  <li>status<br>依照函式引入內容修改棋盤上方的狀態列表訊息</li>
  <li>printBoard<br>使用各種符號，繪出棋盤，且會在main中重複執行，搭配clr達到不斷更新的畫面</li>
  <li>ruleTotal<br>分配各個旗子的規則至各字的函示 例如 rulebin(兵)、rulepow(炮)等等</li>
  <li>inputandselect<br>偵測使用的的輸入座標，檢查其座標位置合理性，確認無誤則轉由ruleTotal，有錯則重新輸入</li>
  <li>winfunc<br>勝利畫面 print 出獲勝玩家 </li>
  <li>main <br>負責程式的主要流程，且在printBoard、inputandselect、clr之間重複執行至獲勝</li>
</ul>
<p>cheeseRule.c</p>
<ul>
  <li>rulecar<br>負責車的邏輯，只能直走、不能飛過東西</li> 
  <li>rulehorse<br>負責法的邏輯，只能日字行走，不得拐馬腳</li>
  <li>rulexian<br>負責相的邏輯，只能田字行走，不得柺相腳及過河</li>
  <li>rulefour<br>負責士的邏輯，只能斜著走，且必須位於九宮格內</li>
  <li>ruleking<br>負責王的邏輯，只能在九宮格內，且王見王可飛過去吃</li>
  <li>rulebin<br>負責兵的邏輯，只能走一步，在自家只能直線走，過河後可橫豎走</li>
  <li>rulepow<br>負責炮的邏輯，只以橫豎走，且可吃掉隔一個棋的敵方棋</li>
</ul>
<h2>程式流程圖</h2>
<img width=600rem src="https://github.com/Ankerrrr/AnkeCC/blob/master/AnkeCC/Untitled%20Diagram.svg">
<h2>使用說明</h2>
<p>▼ 輸入要移動的座標 及 移動到哪裡 即可搬移棋子</p>
<img src="https://github.com/Ankerrrr/AnkeCC/assets/80147818/3c1af165-1d7b-4198-8117-5845414d0162">
<p>▼ 成功搬移棋子</p>
<img src="https://github.com/Ankerrrr/AnkeCC/assets/80147818/d8cee186-45e6-43f4-817d-f5050066905f">
<p>▼ 如果不符合象棋規則則會提示錯誤</p>
<img src="https://github.com/Ankerrrr/AnkeCC/assets/80147818/0c92117c-8bed-4f57-bebe-0117fa4c0772">
<h2>心得反思</h2>
<p>為了做一個真的能夠玩的遊戲，這個中國象棋真的花了我非常多時間及精力，程式的內容幾乎都是自己寫的，少部分是在遇到問題時解決不出來時會尋求CHATGPT的幫助，<br>
  這個程式的架構說大不大但說小也不小，我覺得當初在一開始在設計架構時並沒有想清楚，導致一些函式有過多的工作內容或是變數有些設的有些多餘，在未來撰寫比較大的專案時必須要先規畫清楚，<br>
  最後就是成品看起來還行，但是每次玩都會發現一些BUG，發現一次改一次，在未來自己應該還是會時不時開這個來玩，如果有發現BUG仍然會去修改，如果有發現BUG也歡迎使用issues 頁面反映，謝謝👍</p>
<h2>開發時間</h2>
<img src="https://github.com/Ankerrrr/AnkeCC/assets/80147818/bb0003bd-405c-4a32-a112-cad07b517c5d">
<p>大約25小時</p>




