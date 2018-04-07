$(window).on('load', function () {
  var ft_list = sessionStorage.getItem('ft_list');
  var list = $('#ft_list');

  if (ft_list && list) {
    ft_list = JSON.parse(ft_list);
    for (var todo in ft_list) {
      var p = $('<p></p>');

      if (ft_list.hasOwnProperty(todo)) {
        p.text(ft_list[todo]);
        p.click (function () {
          if (confirm("Delete ?")) {
            $(this).remove();
          }
        });
        list.append(p);
      }
    }
  }
});

$(window).on('unload', function () {
  var list = $('#ft_list');

  if (list) {
    var ft_list = [];

    list.find('p').each(function () {
      ft_list.push($(this).text());
    });
    sessionStorage.setItem('ft_list', JSON.stringify(ft_list));
  }
});

function askTodo() {
  var todo = prompt("What did u have todo ?", "Todo");

  if (todo) {
    var list = $('#ft_list');

    if (list) {
      var p = $('<p></p>');

      p.text(todo);
      p.click(function () {
        if (confirm("Delete ?")) {
          $(this).remove();
        }
      });
      p.prependTo('#ft_list');
    }
  }
}
