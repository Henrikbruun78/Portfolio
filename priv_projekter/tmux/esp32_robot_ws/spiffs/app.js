const canvas = document.getElementById("joy");
const ctx = canvas.getContext("2d");
const dirEl = document.getElementById("dir");
const speedEl = document.getElementById("speed");
const statusEl = document.getElementById("status");

const radius = 110;
const center = { x: canvas.width / 2, y: canvas.height / 2 };

function drawBackground() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  ctx.strokeStyle = "#334155";
  ctx.lineWidth = 2;
  ctx.beginPath();
  ctx.arc(center.x, center.y, radius, 0, Math.PI * 2);
  ctx.stroke();
}

function drawBall(nx, ny) {
  drawBackground();
  const x = center.x + nx * radius;
  const y = center.y + ny * radius;
  ctx.fillStyle = "#38bdf8";
  ctx.beginPath();
  ctx.arc(x, y, 12, 0, Math.PI * 2);
  ctx.fill();
}

function connectWS() {
  const ws = new WebSocket(`ws://${location.host}/ws`);
  ws.onopen = () => statusEl.textContent = "Connected";
  ws.onclose = () => {
    statusEl.textContent = "Disconnected - retrying...";
    setTimeout(connectWS, 1000);
  };
  ws.onerror = () => ws.close();
  ws.onmessage = (ev) => {
    try {
      const data = JSON.parse(ev.data);
      const dir = data.dir || "stop";
      const speed = Math.max(0, Math.min(1, data.speed || 0));
      dirEl.textContent = dir;
      speedEl.textContent = speed.toFixed(3);
      const map = {
        up: [0, -1], down: [0, 1], left: [-1, 0], right: [1, 0],
        up_left: [-1, -1], up_right: [1, -1], down_left: [-1, 1], down_right: [1, 1],
        stop: [0, 0],
      };
      const [dx, dy] = map[dir] || [0, 0];
      const norm = Math.min(1, Math.hypot(dx, dy)) || 1;
      const nx = (dx / norm) * speed;
      const ny = (dy / norm) * speed;
      drawBall(nx, ny);
    } catch (e) {
      console.error("bad message", e);
    }
  };
}

drawBackground();
drawBall(0, 0);
connectWS();
