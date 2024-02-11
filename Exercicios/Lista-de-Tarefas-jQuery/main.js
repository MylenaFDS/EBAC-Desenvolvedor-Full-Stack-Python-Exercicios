$(document).ready(function () {
  $('#taskForm').on('submit', function (e) {
    e.preventDefault();
    const taskName = $('#taskName').val();
    if (taskName.trim() !== '') {
      const listItem = $('<li></li>').text(taskName).append('<button class="delete-button">Excluir</button>');
      $('#taskList').append(listItem);
      $('#taskName').val('');
    }
  });

  $('#taskList').on('click', 'li', function () {
    $(this).toggleClass('task-done');
  });

  $('#taskList').on('click', '.delete-button', function (e) {
    e.stopPropagation();
    $(this).closest('li').remove();
  });
});


