const NOTIFICATION_TITLE = 'Electron'
const NOTIFICATION_BODY = 'Test Begin...'
const CLICK_MESSAGE = 'Clicked'

new Notification(NOTIFICATION_TITLE, { body: NOTIFICATION_BODY })
  .onclick = () => document.getElementById("output").innerText = CLICK_MESSAGE