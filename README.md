# Document Editor

A flexible, object-oriented document editor implementation in C++ that demonstrates key design patterns including Strategy, Composite, and Factory patterns for building and persisting structured documents.

## Features

- **Multiple Element Types**: Support for text, images, newlines, and tab spaces
- **Flexible Rendering**: Clean separation between document structure and presentation
- **Pluggable Storage**: Multiple persistence options (file system, database)
- **Extensible Architecture**: Easy to add new element types and storage backends
- **Memory Management**: Proper encapsulation of document elements

## Architecture

### Core Components

#### DocumentElement (Abstract Base)
- **Purpose**: Base class for all document elements
- **Pattern**: Composite Pattern
- **Key Method**: `render()` - converts element to string representation

#### Concrete Elements
- **TextElement**: Renders plain text content
- **ImageElement**: Renders image placeholders with file paths
- **NewLineElement**: Inserts line breaks
- **TabSpaceElement**: Adds tab indentation

#### Document Container
- **Purpose**: Manages collection of document elements
- **Responsibility**: Orchestrates rendering of all contained elements
- **Storage**: Vector-based element management

#### Persistence Layer
- **Persistence**: Abstract interface for storage operations
- **FileStorage**: Saves documents to local file system
- **DBStorage**: Placeholder for database persistence (extensible)
- **Pattern**: Strategy Pattern for storage flexibility

#### DocumentEditor (Facade)
- **Purpose**: Main client interface for document operations
- **Responsibilities**: 
  - Adding different element types
  - Rendering complete documents
  - Coordinating with persistence layer
- **Pattern**: Facade Pattern for simplified client interactions

## Usage Example

```cpp
// Initialize components
Document *document = new Document();
Persistence *persistence = new FileStorage();
DocumentEditor *editor = new DocumentEditor(document, persistence);

// Build document content
editor->addText("Hello, world!");
editor->addNewLine();
editor->addText("This is a document editor example.");
editor->addTabSpace();
editor->addText("Indented content");
editor->addImage("screenshot.png");

// Render and save
cout << editor->renderDocument() << endl;
editor->saveDocument();
```

## Compilation & Execution

```bash
# Compile
g++ -o DocumentEditorOptimized DocumentEditorOptimized.cpp

# Run
./DocumentEditorOptimized
```

## Output Format

The editor produces structured text output:
```
Hello, world!
This is a document editor example.
    Indented content
[Image: screenshot.png]
```

## Design Patterns Implemented

### 1. Composite Pattern
- `DocumentElement` hierarchy allows treating individual elements and collections uniformly
- Enables recursive document structures

### 2. Strategy Pattern  
- `Persistence` interface allows switching storage mechanisms at runtime
- Easy to extend with new storage types (cloud, database, etc.)

### 3. Facade Pattern
- `DocumentEditor` provides simplified interface hiding complex subsystem interactions
- Reduces client coupling to internal document structure

## Extensibility

### Adding New Element Types
```cpp
class BoldTextElement : public DocumentElement {
private:
    string text;
public:
    BoldTextElement(string text) : text(text) {}
    string render() override {
        return "**" + text + "**";
    }
};
```

### Adding New Storage Options
```cpp
class CloudStorage : public Persistence {
public:
    void save(string data) override {
        // Implement cloud storage logic
    }
};
```

### Adding New Editor Features
```cpp
// In DocumentEditor class
void addBoldText(string text) {
    document->addElement(new BoldTextElement(text));
}
```

## File Structure

```
DocumentEditorOptimized.cpp    # Main implementation
document.txt          # Output file (generated)
README.md            # This documentation
```

## Key Benefits

- **Separation of Concerns**: Clear boundaries between document structure, rendering, and persistence
- **Extensibility**: Easy to add new element types and storage options
- **Testability**: Each component can be unit tested independently
- **Flexibility**: Runtime configuration of storage and rendering strategies
- **Maintainability**: Clean interfaces reduce coupling between components

## Future Enhancements

- **Undo/Redo Operations**: Command pattern for operation history
- **Document Formatting**: Rich text formatting options (bold, italic, colors)
- **Template System**: Predefined document templates
- **Export Formats**: PDF, HTML, Markdown output options
- **Collaborative Editing**: Real-time multi-user editing capabilities
- **Plugin Architecture**: Dynamic loading of custom element types

## Technical Requirements

- **C++ Standard**: C++11 or later
- **Dependencies**: Standard Library only
- **Compiler**: GCC, Clang, or MSVC
- **Platform**: Cross-platform compatible
