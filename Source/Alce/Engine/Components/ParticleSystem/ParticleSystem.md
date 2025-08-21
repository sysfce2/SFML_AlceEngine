# 🧩 ParticleSystem

The ```ParticleSystem``` component manages the emission, update, and destruction of multiple particles.
It defines when and where particles are spawned, and applies a user-defined configuration function (behavior lambda) to each one.
Typical use cases include explosions, fire, smoke, sparks, or magical effects.

## Behaviour

When ```Emit``` is active, the system periodically spawns new particles inside the defined ```emitArea```.
Each new particle is configured using the provided behavior lambda, then added to the scene and updated every frame.

Particles automatically expire once their lifetime ends, at which point they are destroyed and removed from the system.

A debug visualization is also available, rendering the emission area as an outline in the scene.

## Constructors

### Default Constructor
```cpp
ParticleSystem()
```

Creates a new ```ParticleSystem``` with no emission. Emission begins only after Emit is called.

## Public Fields

* ```Time delay```: Interval between consecutive particle emissions.

* ```ShapePtr emitArea```: Area from which particles are spawned (rect, circle, or polygon).

* ```bool enableCollision```: Whether emitted particles participate in collisions.

## Public Methods

### SetDelay
```cpp
void SetDelay(Time delay)
```

Defines the emission interval.

### SetEmitArea
```cpp
void SetEmitArea(ShapePtr emitArea)
```

Sets the spawn area for new particles.

### Emit
```cpp
void Emit()
```

Starts emitting particles.

### Stop
```cpp
void Stop()
```

Stops emission and resets timer.


# ✳️ Particle

The ```Particle``` entity represents a lightweight physics-driven object with a limited lifetime, typically used for visual effects such as sparks, smoke, or debris.
It exposes basic physical properties (density, friction, restitution, damping, velocity) and can optionally interact with the physics world through collisions.
Particles are managed by a ```ParticleSystem``` and are not intended to behave as full gameplay entities.

## Behaviour

On every update, the particle reduces its lifetime and updates its transform based on the underlying physics body.
Once its lifetime reaches zero, the particle is destroyed and removed from the system.

Particles can receive forces, impulses, velocities, damping, and torque to control their short-lived behavior.

## Constructors

### Default Constructor
```cpp
Particle()
```

Creates a new ```Particle``` instance with default parameters. The physics body is created when ```Create``` is called.

## Public Fields

* ```Time lifetime```: Duration until the particle is automatically destroyed.

* ```Transform transform```: Current world position and rotation of the particle.

* ```ShapePtr shape```: Collision shape of the particle (default: 25×25 rectangle).

## Public Methods

### Create
```cpp
void Create(Vector2 position, bool enableCollision)
```

Initializes the particle with a physics body at the given position.

### SetDensity
```cpp
void SetDensity(float density)
```

Updates the body’s mass density.

### SetFriction
```cpp
void SetFriction(float friction)
```

Sets surface friction.

### SetRestitution
```cpp
void SetRestitution(float restitution)
```

Sets elasticity for bounces.

### SetRestitutionThreshold
```cpp
void SetRestitutionThreshold(float threshold)
```

Controls minimum collision impulse for restitution.

### ApplyForce
```cpp
void ApplyForce(Vector2 force, bool wake)
```

Applies continuous force at the center.

### ApplyLinearForce
```cpp
void ApplyLinearForce(Vector2 force, bool wake)
```

Applies an instantaneous impulse.

### SetLinearVelocity
```cpp
void SetLinearVelocity(Vector2 velocity)
```

Directly sets velocity.

### SetHorizontalVelocity
```cpp
void SetHorizontalVelocity(float vy) 
```

Adjusts only vertical velocity.

### SetVerticalVelocity
```cpp
void SetVerticalVelocity(float vx)
```

Adjusts only horizontal velocity.

### SetAngularVelocity
```cpp
void SetAngularVelocity(float va)
```

Sets rotation speed.

### SetAngularDamping
```cpp
void SetAngularDamping(float ad)
```

Slows down angular motion.

### SetLinearDamping
```cpp
void SetLinearDamping(float ld)
```

Slows down linear motion.

### ApplyAngularImpulse
```cpp
void ApplyAngularImpulse(float impulse)
```

Applies a rotation impulse.

### ApplyTorque
```cpp
void ApplyTorque(float torque, bool wake)
```

Applies continuous torque.

### SetAngle
```cpp
void SetAngle(float angle)
```

Rotates the body to the given angle.

### SetFixedRotation
```cpp
void SetFixedRotation(bool flag)
```

Locks/unlocks rotation.

### SetLifetime
```cpp
void SetLifetime(Time lifetime)
```

Defines how long the particle will live.

