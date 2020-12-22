import matplotlib
import matplotlib.pyplot as plt 

matplotlib.rcParams['text.usetex'] = True

fig, ax = plt.subplots()
ax.set_xlim(-0.5, 4)
ax.set_ylim(-0.5, 4)
ax.set_axis_off()

ax.quiver(0, 0, 3, 3, scale_units='xy', angles='xy', scale=1, color='C0')
ax.quiver(0, 0, 1.5, 1.5, scale_units='xy', angles='xy', scale=1, color='C3')

ax.text(0.75, 0.75 + 0.2, '$\\vec{v}$', fontsize=20)
ax.text(2 - 0.1, 2 + 0.2, '$2\\vec{v}$', fontsize=20)

ax.axvline(color='black', linewidth=1.5)
ax.axhline(color='black', linewidth=1.5)

ax.text(0.1, 4, '$y$', fontsize=20)
ax.text(4, 0.1, '$x$', fontsize=20)

plt.show()
