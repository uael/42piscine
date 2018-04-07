window.onload = function () {
	var ft_list = sessionStorage.getItem('ft_list');
  var list = document.getElementById('ft_list');

	if (ft_list && list) {
		ft_list = JSON.parse(ft_list);
		for (var todo in ft_list) {
      var p = document.createElement('p');

      if (ft_list.hasOwnProperty(todo)) {
        p.innerHTML = ft_list[todo];
        p.onclick = function (e) {
          if (confirm("Delete ?")) {
            e.target.remove();
          }
        };
        list.appendChild(p);
			}
		}
	}
};

window.onunload = function () {
  var list = document.getElementById('ft_list');

  if (list) {
    var ft_list = [];
    var children = list.childNodes;

    for(var i = 0; i < children.length; i++) {
      if(children[i].nodeName == "P") {
        ft_list.push(children[i].innerHTML);
      }
    }
    sessionStorage.setItem('ft_list', JSON.stringify(ft_list));
  }
};

function askTodo() {
  var todo = prompt("What did u have todo ?", "Todo");

  if (todo) {
  	var list = document.getElementById('ft_list');

  	if (list) {
  		var p = document.createElement('p');

  		p.innerHTML = todo;
  		p.onclick = function (e) {
  			if (confirm("Delete ?")) {
          e.target.remove();
				}
      };
  		list.prepend(p);
		}
	}
}
