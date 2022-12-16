    <script type="module">
        import { initializeApp } from "https://www.gstatic.com/firebasejs/9.11.0/firebase-app.js";
        import { getDatabase, ref, onValue, set } from "https://www.gstatic.com/firebasejs/9.11.0/firebase-database.js";
        const firebaseConfig = {
      apiKey: "AIzaSyDEvO0STxZnG0xCDe681xHI4IE0npRNsvI",
      authDomain: "asjadeinternet-67555.firebaseapp.com",
      databaseURL: "https://asjadeinternet-67555-default-rtdb.europe-west1.firebasedatabase.app",
      projectId: "asjadeinternet-67555",
      storageBucket: "asjadeinternet-67555.appspot.com",
      messagingSenderId: "975599847990",
      appId: "1:975599847990:web:855f48a51822d1ec146697"
    };
      const app = initializeApp(firebaseConfig);
      const db=getDatabase();
      const trafficSignal = ref(db,"1008")
      onValue(trafficSignal, kuva);
      function kuva(viit){
        let sisu=viit.val();
          console.log(sisu);  
      }
        var green=document.getElementById("green");
        var red=document.getElementById("red");
        var yellow=document.getElementById("yellow");
        var green2=document.getElementById("green2");
        var red2=document.getElementById("red2");
        green.style.opacity = 1;
        red2.style.opacity=1;
        set(trafficSignal, {"valgus1":"roheline"});

        let autoChange = function () {
            console.log("load");
            function startTrafficSignal () {
                set(trafficSignal, {"valgus1":"roheline"});
                setTimeout(function () {
                    green.style.opacity=.3;
                    red.style.opacity=.3;
                    yellow.style.opacity=1;
                    set(trafficSignal, {"valgus1":"kollane"});
                },2000);
                setTimeout(function () {
                    green.style.opacity=.3;
                    red.style.opacity=1;      
                    yellow.style.opacity=.3;
                    set(trafficSignal, {"valgus1":"punane"});
                },4000);
                setTimeout(function () {
                    green.style.opacity=.3;
                    red.style.opacity=.3;
                    yellow.style.opacity=1;
                    set(trafficSignal, {"valgus1":"kollane"});
                },10000);
                setTimeout(function () {
                    green.style.opacity=1;
                    red.style.opacity=.3;
                    yellow.style.opacity=.3;
                    set(trafficSignal, {"valgus1":"roheline"});
                },12000);
            }
            startTrafficSignal();
        }
        let autoChange2 = setInterval(autoChange, 20000);

        window.pressForGreen = function () {
            console.log("click");
            clearInterval(autoChange2);
            function startTrafficSignal () {
                setTimeout(function () {
                    green.style.opacity=.3;
                    red.style.opacity=.3;
                    red2.style.opacity=1;
                    yellow.style.opacity=1;
                    set(trafficSignal, {"valgus1":"kollane"});
                },2000);
                setTimeout(function () {
                    green.style.opacity=.3;
                    red.style.opacity=1;      
                    red2.style.opacity=.3;   
                    yellow.style.opacity=.3;
                    green2.style.opacity = 1;
                    set(trafficSignal, {"valgus2":"roheline"});
                },4000);
                setTimeout(function () {
                    green.style.opacity=.3;
                    red.style.opacity=.3;
                    yellow.style.opacity=1;
                    set(trafficSignal, {"valgus1":"kollane"});
                },7000);
                setTimeout(function () {
                    green2.style.opacity=.3;
                    green.style.opacity=1;
                    red.style.opacity=.3;
                    red2.style.opacity=1;
                    yellow.style.opacity=.3;
                    set(trafficSignal, {"valgus1":"roheline"});;
                    autoChange2 = setInterval(autoChange, 20000);
                },10000);
            }
            startTrafficSignal();
        }
        window.pressForYellow = function (){
            setInterval(function () {
            function startYellow () {
                console.log("click");
                clearInterval(autoChange2);
                setTimeout(function () {
                    yellow.style.opacity=1;
                    green.style.opacity=.3;
                    red2.style.opacity=.3;
                    set(trafficSignal, {"valgus2":"kollane1"});
                }, 2000);
                setTimeout(function () {
                    yellow.style.opacity=.3;
                    set(trafficSignal, {"valgus2":"kollane2"});
                }, 1000);
            }
            startYellow();
        }, 3000);
    }
        window.greenCoridor = function(){
            console.log("cleared");
            clearInterval(autoChange2);
        }

        window.auto = function(){
            console.log("auto")
            autoChange2 = setInterval(autoChange, 20000);
        }

        </script> 
